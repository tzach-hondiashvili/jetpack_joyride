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
    int numCoins = 25;
    std::list<std::unique_ptr <Pickable>> temp;
    
    // Initial positions for rectangle shape
    float startX = 100.f;
    float startY = 100.f;

    // Calculate updated positions after applying scroll offset
    startX += scrollOffset.x;
    startY += scrollOffset.y;


    // Calculate positions for each coin in the diamond shape
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            int index = i * 5 + j; // Compute index in the vertex array
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
    int numCoins = 20; // Number of coins in the rectangle shape (adjust as needed)
    std::list<std::unique_ptr <Pickable>> temp;

    // Initial positions for rectangle shape
    float startX = 100.f;
    float startY = 100.f;

    // Calculate updated positions after applying scroll offset
    startX += scrollOffset.x;
    startY += scrollOffset.y;

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 5; ++j)
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
    int numCoins = 10; // Number of coins in the triangle shape (adjust as needed)
    std::list<std::unique_ptr <Pickable>> temp;

    // Initial positions for triangle shape
    float startX = 100.f;
    float startY = 100.f;

    // Calculate updated positions after applying scroll offset
    startX += scrollOffset.x;
    startY += scrollOffset.y;

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            sf::Vector2f position(startX + j * 40.f, startY + i * 40.f);
   
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
    int numCoins = 50; // Number of coins in the circle shape (adjust as needed)
    std::list<std::unique_ptr <Pickable>> temp;

    // Initial positions for circle shape
    float centerX = 300.f;
    float centerY = 300.f;

    // Calculate updated positions after applying scroll offset
    centerX += scrollOffset.x;
    centerY += scrollOffset.y;

    for (int i = 0; i < numCoins; ++i)
    {
        float angle = i * (360.f / numCoins);
        float radius = 100.f;
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

    // Initial positions for heart shape
    float centerX = 400.f;
    float centerY = 300.f;

    // Calculate updated positions after applying scroll offset
    centerX += scrollOffset.x;
    centerY += scrollOffset.y;

    for (int i = 0; i < numCoins; ++i)
    {
        float angle = i * (360.f / numCoins);
        float radius = 80.f;
        float x = radius * 16.f * std::pow(std::sin(angle * 3.14f / 180.f), 3.f);
        float y = -radius * (13.f * std::cos(angle * 3.14f / 180.f) - 5.f * std::cos(2.f * angle * 3.14f / 180.f) -
            2.f * std::cos(3.f * angle * 3.14f / 180.f) - std::cos(4.f * angle * 3.14f / 180.f));
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

std::list<std::unique_ptr<Pickable>> Factory::createAndGetPickables(sf::Vector2f scrollOffset)
{
    std::srand(std::time(0));

    using CreateFunction = std::list<std::unique_ptr<Pickable>>(*)(const std::string&, sf::Vector2f);


    // Map random numbers to shape creation functions
    static std::map<int, CreateFunction> FunctionMap =
    {
        {0, &Factory::createDiamond},
        {1, &Factory::createRectangle},
        {2, &Factory::createTriangle},
        {3, &Factory::createCircle},
        {4, &Factory::createHeart}
    };

    // Generate a random number between 0 and 4
    int randomNumber = std::rand() % 5;
    std::list<std::unique_ptr<Pickable>> basic;

    // Find the corresponding creation function and call it
    auto it = FunctionMap.find(randomNumber);
    if (it != FunctionMap.end())
    {
        CreateFunction createFunc = it->second;
        std::list<std::unique_ptr<Pickable>> temp = createFunc("Coin", scrollOffset);
        basic.insert(basic.end(), std::make_move_iterator(temp.begin()), std::make_move_iterator(temp.end()));
    }
   
    return basic;
}