#include "CollisionHandling.h"

#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <typeindex>

#include "Player.h"
#include "Coin.h"
#include "Beam.h"
#include "Lazer.h"
#include "PowerUp.h"



namespace // anonymous namespace — the standard way to make function "static"
{

    // primary collision-processing functions
    //void shipAsteroid(GameObject& /*spaceShip*/,
    //    GameObject& /*asteroid*/)
    //{
    //    // To get the actual types and use them:
    //    // SpaceShip& ship = dynamic_cast<SpaceShip&>(spaceShip);
    //    // Asteroid&  ast  = dynamic_cast<Asteroid&>(asteroid);
    //    // or:
    //    // SpaceShip& ship = static_cast<SpaceShip&>(spaceShip);
    //    // Asteroid&  ast  = static_cast<Asteroid&>(asteroid);

    //    std::cout << "SpaceShip and Asteroid collision!\n";
    //}

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
       static_cast<Player&>(player).die();

       static sf::Sound Zap;
       Zap.setBuffer(Resources::instance().getSoundEffect(5));
       Zap.setVolume(100);
       Zap.play();
   }

   void PlayerLazer(GameObjects& player,
       GameObjects& )
   {
       static_cast<Player&>(player).die();

       static sf::Sound Zap;
       Zap.setBuffer(Resources::instance().getSoundEffect(5));
       Zap.setVolume(100);
       Zap.play();
   }

   void PlayerMissile(GameObjects& player,
       GameObjects& )
   {
       static_cast<Player&>(player).die();

       static sf::Sound boom;
       boom.setBuffer(Resources::instance().getSoundEffect(6));
       boom.setVolume(100);
       boom.play();
   }

   void PlayerPowerUp(GameObjects& player,
       GameObjects& )
   {
       static sf::Sound power;
       power.setBuffer(Resources::instance().getSoundEffect(1));
       power.setVolume(100);
       power.play();
   }
  

    //void shipShip(GameObject& /*spaceShip1*/,
    //    GameObject& /*spaceShip2*/)
    //{
    //    std::cout << "Two SpaceShips collision!\n";
    //}

    ////...

    //// secondary collision-processing functions that just
    //// implement symmetry: swap the parameters and call a
    //// primary function
    //void asteroidShip(GameObject& asteroid,
    //    GameObject& spaceShip)
    //{
    //    shipAsteroid(spaceShip, asteroid);
    //}
    //void stationShip(GameObject& spaceStation,
    //    GameObject& spaceShip)
    //{
    //    shipStation(spaceShip, spaceStation);
    //}
    //void stationAsteroid(GameObject& spaceStation,
    //    GameObject& asteroid)
    //{
    //    asteroidStation(asteroid, spaceStation);
    //}
    //...

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
        //phm[Key(typeid(SpaceShip), typeid(SpaceStation))] = &shipStation;
        //phm[Key(typeid(Asteroid), typeid(SpaceStation))] = &asteroidStation;
        //phm[Key(typeid(SpaceShip), typeid(SpaceShip))] = &shipShip;
        //phm[Key(typeid(Asteroid), typeid(SpaceShip))] = &asteroidShip;
        //phm[Key(typeid(SpaceStation), typeid(SpaceShip))] = &stationShip;
        //phm[Key(typeid(SpaceStation), typeid(Asteroid))] = &stationAsteroid;
        //...
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
