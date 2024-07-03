#include "CollisionHandling.h"

#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <typeindex>

#include "Player.h"
#include "FastPlayerState.h"
#include "SpeedBoost.h"
#include "Menu.h"
#include "Coin.h"
#include "Beam.h"
#include "Lazer.h"
#include "PowerUp.h"
#include "MechState.h"
#include "ReverserState.h"
#include "Pig.h"


using CreateFunction = std::function<void(Player& player)>;

namespace 
{

    void CreateReverserState(Player& player) {
        player.getState() = std::move(std::make_unique<ReverserState>(
            player.getState()->getCurrSkin().getPosition(),
            player.getState()->getMenu()
        ));
    }

    void CreateMechState(Player& player) {
        player.getState() = std::move(std::make_unique<MechState>(
            player.getState()->getCurrSkin().getPosition(),
            player.getState()->getMenu()
        ));
    }


    void playerCoin(GameObjects& player,
        GameObjects& )
    {
        static_cast<Player&>(player).collectCoin();

        static sf::Sound pickupCoin;
        pickupCoin.setBuffer(Resources::instance().getSoundEffect(0));
        pickupCoin.setVolume(100);
        pickupCoin.play();
    }

   void PlayerBeam(GameObjects& player,
       GameObjects& )
   {
       static_cast<Player&>(player).getState()->die();

       static sf::Sound Zap;
       Zap.setBuffer(Resources::instance().getSoundEffect(5));
       Zap.setVolume(100);
       Zap.play();
   }

   void PlayerLazer(GameObjects& player,
       GameObjects& )
   {
       static_cast<Player&>(player).getState()->die();

       static sf::Sound Zap;
       Zap.setBuffer(Resources::instance().getSoundEffect(5));
       Zap.setVolume(100);
       Zap.play();
   }

   void PlayerMissile(GameObjects& player,
       GameObjects& )
   {
       static_cast<Player&>(player).getState()->die();

       static sf::Sound boom;
       boom.setBuffer(Resources::instance().getSoundEffect(6));
       boom.setVolume(100);
       boom.play();
   }

   void PlayerPig(GameObjects& player,
       GameObjects& pig)
   {
       
       static_cast<Player&>(player).getState()->getMenu()->getController().getMap().updatePickablesWithPigCoin(pig.getSprite().getPosition());
       
       static sf::Sound pigParty;
       pigParty.setBuffer(Resources::instance().getSoundEffect(13));
       pigParty.setVolume(100);
       pigParty.play();
   }

   void PlayerPowerUp(GameObjects& player,
       GameObjects& )
   {
       static std::map<int, CreateFunction> PowerupMap = 
       {
            {0, CreateReverserState},
            {1, CreateMechState}
       };
       
       int choice = rand() % 2;
       
       auto it = PowerupMap.find(choice);
       if (it != PowerupMap.end())
       {
           it->second(static_cast<Player&>(player));
       }

       static sf::Sound power;
       power.setBuffer(Resources::instance().getSoundEffect(1));
       power.setVolume(100);
       power.play();
   }
  
   void PlayerSpeedBoost(GameObjects& player,
       GameObjects& speedBoost)
   {

       static_cast<Player&>(player).getState() = std::move(std::make_unique<FastPlayerState>(
                                                 static_cast<Player&>(player).getState()->getCurrSkin().getPosition(),
                                                 static_cast<Player&>(player).getState()->getMenu()));

       static sf::Sound speedBoostSound;
       speedBoostSound.setBuffer(Resources::instance().getSoundEffect(16));
       speedBoostSound.setVolume(100);
       speedBoostSound.play();
   }
    

    using HitFunctionPtr = void (*)(GameObjects&, GameObjects&);
    using Key = std::pair<std::type_index, std::type_index>;
    using HitMap = std::map<Key, HitFunctionPtr>;

    HitMap initializeCollisionMap()
    {
        HitMap phm;
        phm[Key(typeid(Player), typeid(Coin))] = &playerCoin; 
        phm[Key(typeid(Player), typeid(Beam))] = &PlayerBeam;
        phm[Key(typeid(Player), typeid(Lazer))] = &PlayerLazer;
        phm[Key(typeid(Player), typeid(Missile))] = &PlayerMissile;
        phm[Key(typeid(Player), typeid(PowerUp))] = &PlayerPowerUp;
        phm[Key(typeid(Player), typeid(Pig))] = &PlayerPig;
        phm[Key(typeid(Player), typeid(SpeedBoost))] = &PlayerSpeedBoost;
        
        return phm;
    }
    
    HitFunctionPtr lookup(const std::type_index& class1, const std::type_index& class2)
    {
        static HitMap collisionMap = initializeCollisionMap();
        auto mapEntry = collisionMap.find(std::make_pair(class1, class2));
        if (mapEntry == collisionMap.end())
        {
            return nullptr;
        }
        return mapEntry->second;
    }

} // end namespace

void processCollision(GameObjects& object1, GameObjects& object2)
{
    auto phf = lookup(typeid(object1), typeid(object2));
    if (!phf)
    {
        throw UnknownCollision(object1, object2);
    }
    phf(object1, object2);
}
