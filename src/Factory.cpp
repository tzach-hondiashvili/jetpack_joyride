#include "Factory.h"

//Create a GameObject instance based on the provided name.
std::unique_ptr<GameObjects> Factory::create(const std::string& name, sf::Vector2f position)
{
	auto it = getMap().find(name);
	if (it == getMap().end())
		return nullptr;
	return it->second(position);
}

//Register a factory function for creating a GameObject by name.
bool Factory::registerit(const std::string& name, std::unique_ptr<GameObjects>(*f)(sf::Vector2f position))
{
	getMap().emplace(name, f);
	return true;
}

std::list<std::unique_ptr<Pickable>> Factory::createDiamond(const std::string& name, sf::Vector2f scrollOffset)
{
    std::list<std::unique_ptr <Pickable>> temp;
    
    // Initial positions for rectangle shape
    float startX = 100.f;
    float startY = 100.f;

    // Calculate updated positions after applying scroll offset  
    
    int randomNumberX = std::rand() % (1456-100);
    int randomNumberY = std::rand() % (960-260);
    startX += scrollOffset.x + randomNumberX;
    startY += scrollOffset.y + randomNumberY;

    // Calculate positions for each coin in the diamond shape
    int halfSize = (std::rand() % 3) + 1; // Half the size of the diamond (adjust as needed)
    for (int i = -halfSize; i <= halfSize; ++i)
    {
        int steps = halfSize - std::abs(i);
        for (int j = -steps; j <= steps; ++j)
        {
            sf::Vector2f position(startX + i * 50.f, startY + j * 40.f);

            // Create a GameObject instance
            std::unique_ptr<GameObjects> coin = Factory::create(name, position);
            if (coin)
            {
                // Downcast to Pickable by transferring ownership and casting raw pointer
                std::unique_ptr<Pickable> pickable(static_cast<Pickable*>(coin.release()));

                // Add to temp
                temp.push_back(std::move(pickable));
            }
        }
    }
    return temp;
}

std::list<std::unique_ptr<Pickable>> Factory::createRectangle(const std::string& name, sf::Vector2f scrollOffset)
{
    std::list<std::unique_ptr <Pickable>> temp;

    // Initial positions for rectangle shape
    float startX = 100.f;
    float startY = 100.f;

    // Calculate updated positions after applying scroll offset
    int randomNumberX = std::rand() % (1456 - 100);
    int randomNumberY = std::rand() % (960 - 260);
    startX += scrollOffset.x + randomNumberX;
    startY += scrollOffset.y + randomNumberY;

    float width = (float)(std::rand() % 6) + 1; // Adjust range and base size as needed
    float height = (float)(std::rand() % 6) + 1;

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            sf::Vector2f position(startX + i * 50.f, startY + j * 40.f);
     
            // Create a GameObject instance
            std::unique_ptr<GameObjects> coin = Factory::create(name, position);
            if (coin)
            {
                // Downcast to Pickable by transferring ownership and casting raw pointer
                std::unique_ptr<Pickable> pickable(static_cast<Pickable*>(coin.release()));

                // Add to temp
                temp.push_back(std::move(pickable));
            }
        }
    }
    return temp;
}

std::list<std::unique_ptr<Pickable>> Factory::createTriangle(const std::string& name, sf::Vector2f scrollOffset)
{
    std::list<std::unique_ptr <Pickable>> temp;

    float startX = 100.f;
    float startY = 100.f;

    // Calculate updated positions after applying scroll offset and randomization
    int randomNumberX = std::rand() % (1456 - 100);
    int randomNumberY = std::rand() % (960 - 400);
    startX += scrollOffset.x + randomNumberX;
    startY += scrollOffset.y + randomNumberY;

    // Randomize the size of the triangle
    int baseLength = (std::rand() % 11) + 1; // Adjust range and base size as needed
    int height = (std::rand() % 7) + 1;

    for (int i = 0; i < height; ++i)
    {
        int spaces = height - i - 1; // Decreasing spaces as we move upwards
        for (int j = 0; j <= spaces; ++j)
        {
            // Calculate horizontal position for centering the triangle
            float centerX = startX + baseLength * 20.f / 2.f;
            float positionX = centerX - i * 20.f + j * 40.f;

            // Calculate vertical position
            float positionY = startY + i * 40.f;

            sf::Vector2f position(positionX, positionY);
            // Create a GameObject instance
            std::unique_ptr<GameObjects> coin = Factory::create(name, position);
            if (coin)
            {
                // Downcast to Pickable by transferring ownership and casting raw pointer
                std::unique_ptr<Pickable> pickable(static_cast<Pickable*>(coin.release()));

                // Add to temp
                temp.push_back(std::move(pickable));
            }
        }
    }
    return temp;
}

std::list<std::unique_ptr<Pickable>> Factory::createCircle(const std::string& name, sf::Vector2f scrollOffset)
{
    int numCoins = 30; // Number of coins in the circle shape (adjust as needed)
    std::list<std::unique_ptr <Pickable>> temp;

    // Randomize center position within a range
    float centerX = 100.f + static_cast<float>(std::rand() % 1356) + scrollOffset.x;
    float centerY = 260.f + static_cast<float>(std::rand() % 400) + scrollOffset.y;
    
    // Randomize radius within a range
    float minRadius = 75.f;
    float maxRadius = 150.f;
    float radius = minRadius + static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX / (maxRadius - minRadius)));

    for (int i = 0; i < numCoins; ++i)
    {
        float angle = i * (360.f / numCoins);
        sf::Vector2f position(centerX + std::cos(angle * 3.14f / 180.f) * radius,
            centerY + std::sin(angle * 3.14f / 180.f) * radius);

        // Create a GameObject instance
        std::unique_ptr<GameObjects> coin = Factory::create(name, position);
        if (coin)
        {
            // Downcast to Pickable by transferring ownership and casting raw pointer
            std::unique_ptr<Pickable> pickable(static_cast<Pickable*>(coin.release()));

            // Add to temp
            temp.push_back(std::move(pickable));
        }
    }
    return temp;
}

std::list<std::unique_ptr<Pickable>> Factory::createHeart(const std::string& name, sf::Vector2f scrollOffset)
{
    int numCoins = 30; // Number of coins in the heart shape (adjust as needed)
    std::list<std::unique_ptr <Pickable>> temp;

    // Randomize center position within a range
    float minX = 100.f;
    float maxX = 700.f;
    float minY = 100.f;
    float maxY = 500.f;
    float centerX = minX + static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX / (maxX - minX)));
    float centerY = minY + static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX / (maxY - minY)));

    // Calculate updated positions after applying scroll offset
    centerX += scrollOffset.x;
    centerY += scrollOffset.y;

    // Randomize radius within a range
    float minRadius = 15.f;
    float maxRadius = 20.f;
    float radius = minRadius + static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX / (maxRadius - minRadius)));

    for (int i = 0; i < numCoins; ++i)
    {
        float angle = i * (360.f / numCoins);
        float x = radius * 16.f * std::pow(std::sin(angle * 3.14f / 180.f), 3.f);
        float y = -radius * (13.f * std::cos(angle * 3.14f / 180.f) - 5.f * std::cos(2.f * angle * 3.14f / 180.f) -
            2.f * std::cos(3.f * angle * 3.14f / 180.f) - std::cos(4.f * angle * 3.14f / 180.f));

        // Adjust position to fit within the sprite size
        x *= 0.5f; // Scale down x position to fit within 320
        y *= 0.5f; // Scale down y position to fit within 8
        sf::Vector2f position(centerX + x, centerY + y);
        // Create a GameObject instance
        std::unique_ptr<GameObjects> coin = Factory::create(name, position);
        if (coin)
        {
            // Downcast to Pickable by transferring ownership and casting raw pointer
            std::unique_ptr<Pickable> pickable(static_cast<Pickable*>(coin.release()));

            // Add to temp
            temp.push_back(std::move(pickable));
        }
    }
    return temp;
}

std::list<std::unique_ptr<Pickable>> Factory::createPowerup(const std::string& name, sf::Vector2f scrollOffset)
{
    std::list<std::unique_ptr <Pickable>> temp;

    // Randomize center position within a range
    float centerX = 100.f + static_cast<float>(std::rand() % 1356) + scrollOffset.x;
    float centerY = 260.f + static_cast<float>(std::rand() % 400) + scrollOffset.y;

    sf::Vector2f position(centerX, centerY);

        // Create a GameObject instance
        std::unique_ptr<GameObjects> PowerUp = Factory::create(name, position);
        if (PowerUp)
        {
            // Downcast to Pickable by transferring ownership and casting raw pointer
            std::unique_ptr<Pickable> pickable(static_cast<Pickable*>(PowerUp.release()));

            // Add to temp
            temp.push_back(std::move(pickable));
        }
    
    return temp;
}

std::list<std::unique_ptr<Pickable>> Factory::createAndGetPickables(sf::Vector2f scrollOffset)
{
    std::srand((unsigned int)std::time(NULL));

    using CreateFunction = std::list<std::unique_ptr<Pickable>>(*)(const std::string&, sf::Vector2f);

    std::string object;
    // Map random numbers to shape creation functions
    static std::map<int, CreateFunction> FunctionMap =
    {
        {0, &Factory::createDiamond},
        {1, &Factory::createRectangle},
        {2, &Factory::createTriangle},
        {3, &Factory::createCircle},
        {4, &Factory::createHeart},
        {5, &Factory::createPowerup}
    };

    // Generate a random number between 0 and 5
    int randomNumber = std::rand() % 6;
    std::list<std::unique_ptr<Pickable>> basic;

    // Find the corresponding creation function and call it
    auto it = FunctionMap.find(randomNumber);
    if (it != FunctionMap.end())
    {
        if (randomNumber==5)
        {
            object = "PowerUp";
        }
        else
        {
            object = "Coin";
        }
        CreateFunction createFunc = it->second;
        std::list<std::unique_ptr<Pickable>> temp = createFunc(object, scrollOffset);
        basic.insert(basic.end(), std::make_move_iterator(temp.begin()), std::make_move_iterator(temp.end()));
    }
   
    return basic;
}

std::list<std::unique_ptr<StaticObjects>> Factory::createYparallel(const std::string& name, sf::Vector2f scrollOffset)
{
    std::list<std::unique_ptr<StaticObjects>> temp;

    float startX = 100.f + scrollOffset.x + (std::rand() % (1356 - 100));
    float startY = 100.f + scrollOffset.y + (std::rand() % (760 - 400));

    int randomNumber = 100 + std::rand() % 300;

    sf::Vector2f position1(startX, startY);
    sf::Vector2f position2(startX, startY + randomNumber); // Adjust distance as needed

    std::unique_ptr<GameObjects> laserHead1 = Factory::create(name, position1);
    std::unique_ptr<GameObjects> laserHead2 = Factory::create(name, position2);

    laserHead1->rotate(180);
    

    if (laserHead1 && laserHead2)
    {
        // Downcast to StaticObjects
        std::unique_ptr<StaticObjects> staticLaserHead1(static_cast<StaticObjects*>(laserHead1.release()));
        std::unique_ptr<StaticObjects> staticLaserHead2(static_cast<StaticObjects*>(laserHead2.release()));

        // Calculate the midpoint between the two laser heads
        

        // Calculate the distance and angle between the two laser heads
        float deltaX = position2.x - position1.x;
        float deltaY = position2.y - position1.y;
        float distance = std::sqrt(deltaX * deltaX + deltaY * deltaY);

        // Create the beam
        sf::Vector2f beamPosition((position1.x + position2.x) / 2, (position1.y + position2.y) / 2); // Midpoint of the laser heads
        std::unique_ptr<GameObjects> beam = Factory::create("Beam", beamPosition);
        if (beam)
        {
            float originalBeamHeight = beam->getSprite().getLocalBounds().height;
            float scaleY = distance / originalBeamHeight;

            beam->setScale(sf::Vector2f(1, scaleY));
            std::unique_ptr<StaticObjects> staticBeam(static_cast<StaticObjects*>(beam.release()));
            temp.push_back(std::move(staticBeam));
        }
        temp.push_back(std::move(staticLaserHead1));
        temp.push_back(std::move(staticLaserHead2));
    }

    return temp;
}

std::list<std::unique_ptr<StaticObjects>> Factory::createXparallel(const std::string& name, sf::Vector2f scrollOffset)
{
    std::list<std::unique_ptr<StaticObjects>> temp;

    float startX = 100.f + scrollOffset.x + (std::rand() % (1356 - 100));
    float startY = 100.f + scrollOffset.y + (std::rand() % (760 - 100));

    int randomNumber = 100 + (std::rand() % 300);

    sf::Vector2f position1(startX, startY);
    sf::Vector2f position2(startX + randomNumber, startY);

    std::unique_ptr<GameObjects> laserHead1 = Factory::create(name, position1);
    std::unique_ptr<GameObjects> laserHead2 = Factory::create(name, position2);
    laserHead2->rotate(180+90);
    laserHead1->rotate(90);

    if (laserHead1 && laserHead2)
    {
        std::unique_ptr<StaticObjects> staticLaserHead1(static_cast<StaticObjects*>(laserHead1.release()));
        std::unique_ptr<StaticObjects> staticLaserHead2(static_cast<StaticObjects*>(laserHead2.release()));

        // Calculate the distance and angle between the two laser heads
        float deltaX = position2.x - position1.x;
        float deltaY = position2.y - position1.y;
        float distance = std::sqrt(deltaX * deltaX + deltaY * deltaY);

        sf::Vector2f beamPosition(startX + randomNumber / 2.f, startY);
        std::unique_ptr<GameObjects> beam = Factory::create("Beam", beamPosition);
        if (beam)
        {
            float originalBeamHeight = beam->getSprite().getLocalBounds().height;
            float scaleY = distance / originalBeamHeight;

            beam->setScale(sf::Vector2f(1, scaleY));
            beam->rotate(90);

            std::unique_ptr<StaticObjects> staticBeam(static_cast<StaticObjects*>(beam.release()));
            temp.push_back(std::move(staticBeam));
        }
        temp.push_back(std::move(staticLaserHead1));
        temp.push_back(std::move(staticLaserHead2));
    }

    return temp;
}

std::list<std::unique_ptr<StaticObjects>> Factory::createLayingLeft(const std::string& name, sf::Vector2f scrollOffset)
{
    std::list<std::unique_ptr<StaticObjects>> temp;

    float startX = 100.f + scrollOffset.x + (std::rand() % (1356 - 200)); // Adjusted to avoid going out of bounds
    float startY = 150.f + scrollOffset.y + (std::rand() % (760 - 400));

    int randomNumber = 100 + (std::rand() % 200); // Ensure a minimum length

    sf::Vector2f position2(startX - randomNumber, startY);
    sf::Vector2f position1(startX, startY - randomNumber);

    std::unique_ptr<GameObjects> laserHead1 = Factory::create(name, position1);
    std::unique_ptr<GameObjects> laserHead2 = Factory::create(name, position2);

    if (laserHead1 && laserHead2)
    {
        // Calculate the angle between the two positions
        float deltaX = position2.x - position1.x;
        float deltaY = position2.y - position1.y;
        float angle = std::atan2(deltaY, deltaX) * 180.f / (float)3.14159265358979323846;

        // Set the rotations based on the calculated angle
        laserHead1->rotate((int)angle + 90); // Rotate to face left
        laserHead2->rotate((int)angle - 90);         // Rotate to face right

        std::unique_ptr<StaticObjects> staticLaserHead1(static_cast<StaticObjects*>(laserHead1.release()));
        std::unique_ptr<StaticObjects> staticLaserHead2(static_cast<StaticObjects*>(laserHead2.release()));

        // Calculate the distance and angle between the two laser heads
        float distance = std::sqrt(deltaX * deltaX + deltaY * deltaY);

        sf::Vector2f beamPosition((position1.x + position2.x) / 2, (position1.y + position2.y) / 2); // Midpoint of the laser heads
        std::unique_ptr<GameObjects> beam = Factory::create("Beam", beamPosition);
        if (beam)
        {
            float originalBeamHeight = beam->getSprite().getLocalBounds().height;
            float scaleY = distance / originalBeamHeight;

            beam->setScale(sf::Vector2f(1, scaleY));
            beam->rotate(45);

            std::unique_ptr<StaticObjects> staticBeam(static_cast<StaticObjects*>(beam.release()));
            temp.push_back(std::move(staticBeam));
        }  
        temp.push_back(std::move(staticLaserHead1));
        temp.push_back(std::move(staticLaserHead2));
    }

    return temp;
}

std::list<std::unique_ptr<StaticObjects>> Factory::createLayingRight(const std::string& name, sf::Vector2f scrollOffset)
{
    std::list<std::unique_ptr<StaticObjects>> temp;

    float startX = 100.f + scrollOffset.x + (std::rand() % (1356 - 200)); // Adjusted to avoid going out of bounds
    float startY = 150.f + scrollOffset.y + (std::rand() % (760 - 400));

    int randomNumber = 100 + (std::rand() % 200); // Ensure a minimum length

    sf::Vector2f position1(startX - randomNumber, startY - randomNumber);
    sf::Vector2f position2(startX , startY);

    std::unique_ptr<GameObjects> laserHead1 = Factory::create(name, position1);
    std::unique_ptr<GameObjects> laserHead2 = Factory::create(name, position2);

    // Calculate the distance and angle between the two laser heads
    float deltaX = position2.x - position1.x;
    float deltaY = position2.y - position1.y;
    float distance = std::sqrt(deltaX * deltaX + deltaY * deltaY);

    if (laserHead1 && laserHead2)
    {
        // Calculate the angle between the two positions
        float angle = std::atan2(deltaY, deltaX) * 180.f / (float)3.14159265358979323846;

        // Set the rotations based on the calculated angle
        laserHead1->rotate((int)angle + 90); // Rotate to face left
        laserHead2->rotate((int)angle - 90);         // Rotate to face right

        std::unique_ptr<StaticObjects> staticLaserHead1(static_cast<StaticObjects*>(laserHead1.release()));
        std::unique_ptr<StaticObjects> staticLaserHead2(static_cast<StaticObjects*>(laserHead2.release()));

       

        sf::Vector2f beamPosition((position1.x + position2.x) / 2, (position1.y + position2.y) / 2); // Midpoint of the laser heads
        std::unique_ptr<GameObjects> beam = Factory::create("Beam", beamPosition);
        if (beam)
        {
            float originalBeamHeight = beam->getSprite().getLocalBounds().height;
            float scaleY = distance / originalBeamHeight;

            beam->setScale(sf::Vector2f(1, scaleY));
            beam->rotate(360 - 45);

            std::unique_ptr<StaticObjects> staticBeam(static_cast<StaticObjects*>(beam.release()));
            temp.push_back(std::move(staticBeam));
        }
        temp.push_back(std::move(staticLaserHead1));
        temp.push_back(std::move(staticLaserHead2));
    }

    return temp;
}

std::list<std::unique_ptr<StaticObjects>> Factory::createAndGetObstacles(sf::Vector2f scrollOffset)
{
    std::srand((unsigned int)std::time(NULL));

    using CreateFunction = std::list<std::unique_ptr<StaticObjects>>(*)(const std::string&, sf::Vector2f);

    static std::map<int, CreateFunction> FunctionMap =
    {
        {0, &Factory::createYparallel},
        {1, &Factory::createXparallel},
        {2, &Factory::createLayingLeft},
        {3, &Factory::createLayingRight}
    };

    int randomNumber = std::rand() % 6;
    std::list<std::unique_ptr<StaticObjects>> obstacles;

    auto it = FunctionMap.find(randomNumber);
    if (it != FunctionMap.end())
    {
        CreateFunction createFunc = it->second;
        std::list<std::unique_ptr<StaticObjects>> temp = createFunc("Lazer", scrollOffset);
        obstacles.insert(obstacles.end(), std::make_move_iterator(temp.begin()), std::make_move_iterator(temp.end()));
    }

    return obstacles;
}

std::list<std::unique_ptr<Enemy>> Factory::createAndGetEnemies(sf::Vector2f scrollOffset, sf::Vector2f playerPos)
{ 
    std::srand((unsigned int)std::time(NULL));
    
    using CreateFunction = std::list<std::unique_ptr<Enemy>>(*)(const std::string&, sf::Vector2f);
    
    static std::map<int, CreateFunction> FunctionMap =
    {
        {0, &Factory::create4together},
        {1, &Factory::create2together},
        {2, &Factory::create4oneByOne},
        {3, &Factory::create2oneByOne},
        {4, &Factory::createMissile}
    };
    
    int randomNumber = std::rand() % 10;
    std::list<std::unique_ptr<Enemy>> enemies;
    
    auto it = FunctionMap.find(randomNumber);
    if (it != FunctionMap.end())
    {
        CreateFunction createFunc = it->second;
        std::list<std::unique_ptr<Enemy>> temp = createFunc("Missile", { scrollOffset.x , playerPos.y});
        enemies.insert(enemies.end(), std::make_move_iterator(temp.begin()), std::make_move_iterator(temp.end()));
    }
    
    return enemies;
}

std::list<std::unique_ptr<Enemy>> Factory::createMissile(const std::string& name, sf::Vector2f scrollOffset)
{
    std::list<std::unique_ptr<Enemy>> temp;

    // Calculate starting position outside the screen on the right side
    float startX = 2000 + scrollOffset.x; 
    float startY = scrollOffset.y + 50;

    sf::Vector2f position(startX, startY);

    // Create the missile
    std::unique_ptr<GameObjects> missile = Factory::create(name, position);

    std::unique_ptr<Enemy> enemyObject(static_cast<Enemy*>(missile.release()));
    temp.push_back(std::move(enemyObject));

    return temp;
}

std::list<std::unique_ptr<Enemy>> Factory::create2oneByOne(const std::string& name, sf::Vector2f scrollOffset)
{
    std::list<std::unique_ptr<Enemy>> temp;

    // Calculate starting position outside the screen on the right side
    float startX = 2000 + scrollOffset.x;
    float startY = scrollOffset.y + 50;

    sf::Vector2f position1(startX, startY+20);
    sf::Vector2f position2(startX+200, startY);

    // Create the missile
    std::unique_ptr<GameObjects> missile1 = Factory::create(name, position1);
    std::unique_ptr<GameObjects> missile2 = Factory::create(name, position2);

    std::unique_ptr<Enemy> enemyObject1(static_cast<Enemy*>(missile1.release()));
    temp.push_back(std::move(enemyObject1));
    std::unique_ptr<Enemy> enemyObject2(static_cast<Enemy*>(missile2.release()));
    temp.push_back(std::move(enemyObject2));

    return temp;
}

std::list<std::unique_ptr<Enemy>> Factory::create4oneByOne(const std::string& name, sf::Vector2f scrollOffset)
{
    std::list<std::unique_ptr<Enemy>> temp;

    // Calculate starting position outside the screen on the right side
    float startX = 2000 + scrollOffset.x;
    float startY = scrollOffset.y + 50;

    sf::Vector2f position1(startX, startY);
    sf::Vector2f position2(startX + 200, startY+50);
    sf::Vector2f position3(startX + 350, startY+60);
    sf::Vector2f position4(startX + 280, startY-20);

    // Create the missile
    std::unique_ptr<GameObjects> missile1 = Factory::create(name, position1);
    std::unique_ptr<GameObjects> missile2 = Factory::create(name, position2);
    std::unique_ptr<GameObjects> missile3 = Factory::create(name, position3);
    std::unique_ptr<GameObjects> missile4 = Factory::create(name, position4);

    std::unique_ptr<Enemy> enemyObject1(static_cast<Enemy*>(missile1.release()));
    temp.push_back(std::move(enemyObject1));
    std::unique_ptr<Enemy> enemyObject2(static_cast<Enemy*>(missile2.release()));
    temp.push_back(std::move(enemyObject2));
    std::unique_ptr<Enemy> enemyObject3(static_cast<Enemy*>(missile3.release()));
    temp.push_back(std::move(enemyObject3));
    std::unique_ptr<Enemy> enemyObject4(static_cast<Enemy*>(missile4.release()));
    temp.push_back(std::move(enemyObject4));

    return temp;
}

std::list<std::unique_ptr<Enemy>> Factory::create2together(const std::string& name, sf::Vector2f scrollOffset)
{
    std::list<std::unique_ptr<Enemy>> temp;

    // Calculate starting position outside the screen on the right side
    float startX = 2000 + scrollOffset.x;
    float startY = 150 + scrollOffset.y;

    sf::Vector2f position1(startX, startY-50);
    sf::Vector2f position2(startX, startY+50);
    // Create the missile
    std::unique_ptr<GameObjects> missile1 = Factory::create(name, position1);
    std::unique_ptr<GameObjects> missile2 = Factory::create(name, position2);

    std::unique_ptr<Enemy> enemyObject1(static_cast<Enemy*>(missile1.release()));
    temp.push_back(std::move(enemyObject1));
    std::unique_ptr<Enemy> enemyObject2(static_cast<Enemy*>(missile2.release()));
    temp.push_back(std::move(enemyObject2));

    return temp;
}

std::list<std::unique_ptr<Enemy>> Factory::create4together(const std::string& name, sf::Vector2f scrollOffset)
{
    std::list<std::unique_ptr<Enemy>> temp;

    // Calculate starting position outside the screen on the right side
    float startX = 2000 + scrollOffset.x;
    float startY = 150;

    sf::Vector2f position1(startX, startY);
    sf::Vector2f position2(startX, startY + 120);
    sf::Vector2f position3(startX, startY + 540);
    sf::Vector2f position4(startX, startY + 660);

    // Create the missile
    std::unique_ptr<GameObjects> missile1 = Factory::create(name, position1);
    std::unique_ptr<GameObjects> missile2 = Factory::create(name, position2);
    std::unique_ptr<GameObjects> missile3 = Factory::create(name, position3);
    std::unique_ptr<GameObjects> missile4 = Factory::create(name, position4);

    std::unique_ptr<Enemy> enemyObject1(static_cast<Enemy*>(missile1.release()));
    temp.push_back(std::move(enemyObject1));
    std::unique_ptr<Enemy> enemyObject2(static_cast<Enemy*>(missile2.release()));
    temp.push_back(std::move(enemyObject2));
    std::unique_ptr<Enemy> enemyObject3(static_cast<Enemy*>(missile3.release()));
    temp.push_back(std::move(enemyObject3));
    std::unique_ptr<Enemy> enemyObject4(static_cast<Enemy*>(missile4.release()));
    temp.push_back(std::move(enemyObject4));

    return temp;
}

std::list<std::unique_ptr<MovingObjects>> Factory::createScientists(const std::string& name, sf::Vector2f scrollOffset)
{
    std::srand((unsigned int)std::time(NULL));
    int randomNumber = std::rand() % 400;

    std::list<std::unique_ptr<MovingObjects>> temp;

    // Calculate starting position outside the screen on the right side
    float startX = 1000 + scrollOffset.x;
    float startY = 750;

    sf::Vector2f position1(startX+ randomNumber + 1000, startY);
    sf::Vector2f position2(startX+ randomNumber - 600, startY);
    sf::Vector2f position3(startX- randomNumber + 200, startY);
    sf::Vector2f position4(startX- randomNumber - 1200, startY);
    sf::Vector2f position5(startX, startY);

    // Create the scientists
    std::unique_ptr<GameObjects> scientist1 = Factory::create(name, position1);
    std::unique_ptr<GameObjects> scientist2 = Factory::create(name, position2);
    std::unique_ptr<GameObjects> scientist3 = Factory::create(name, position3);
    std::unique_ptr<GameObjects> scientist4 = Factory::create(name, position4);
    std::unique_ptr<GameObjects> scientist5 = Factory::create(name, position5);

    std::unique_ptr<MovingObjects> scientistObject1(static_cast<MovingObjects*>(scientist1.release()));
    temp.push_back(std::move(scientistObject1));
    std::unique_ptr<MovingObjects> scientistObject2(static_cast<MovingObjects*>(scientist2.release()));
    temp.push_back(std::move(scientistObject2));
    std::unique_ptr<MovingObjects> scientistObject3(static_cast<MovingObjects*>(scientist3.release()));
    temp.push_back(std::move(scientistObject3));
    std::unique_ptr<MovingObjects> scientistObject4(static_cast<MovingObjects*>(scientist4.release()));
    temp.push_back(std::move(scientistObject4));
    std::unique_ptr<MovingObjects> scientistObject5(static_cast<MovingObjects*>(scientist5.release()));
    temp.push_back(std::move(scientistObject5));

    return temp;
}

std::list<std::unique_ptr<MovingObjects>> Factory::createAndGetScientists(sf::Vector2f scrollOffset, sf::Vector2f playerPos)
{
    std::srand((unsigned int)std::time(NULL));
    using CreateFunction = std::list<std::unique_ptr<MovingObjects>>(*)(const std::string&, sf::Vector2f);

    int randomNumber = std::rand() % 3;

    static std::map<int, CreateFunction> FunctionMap =
    {
        {0, &Factory::createScientists}
    };

    std::list<std::unique_ptr<MovingObjects>> scientists;

    auto it = FunctionMap.find(randomNumber);
    if (it != FunctionMap.end())
    {
        CreateFunction createFunc = it->second;
        std::list<std::unique_ptr<MovingObjects>> temp = createFunc("Scientist", { scrollOffset.x , playerPos.y });
        scientists.insert(scientists.end(), std::make_move_iterator(temp.begin()), std::make_move_iterator(temp.end()));
    }

    return scientists;
}