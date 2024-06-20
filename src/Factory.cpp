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
    int numCoins = 20; // Number of coins in the rectangle shape (adjust as needed)
    std::list<std::unique_ptr <Pickable>> temp;

    // Initial positions for rectangle shape
    float startX = 100.f;
    float startY = 100.f;

    // Calculate updated positions after applying scroll offset
    int randomNumberX = std::rand() % (1456 - 100);
    int randomNumberY = std::rand() % (960 - 260);
    startX += scrollOffset.x + randomNumberX;
    startY += scrollOffset.y + randomNumberY;

    float width = (std::rand() % 6) + 1; // Adjust range and base size as needed
    float height = (std::rand() % 6) + 1;

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
    int numCoins = 10; // Number of coins in the triangle shape (adjust as needed)
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
    int numCoins = 50; // Number of coins in the circle shape (adjust as needed)
    std::list<std::unique_ptr <Pickable>> temp;

    // Randomize center position within a range
    float centerX = 100.f + static_cast<float>(std::rand() % 1356) + scrollOffset.x;
    float centerY = 260.f + static_cast<float>(std::rand() % 400) + scrollOffset.y;
    
    // Randomize radius within a range
    float minRadius = 50.f;
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
    float minRadius = 20.f;
    float maxRadius = 40.f;
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

std::list<std::unique_ptr<Pickable>> Factory::createAndGetPickables(sf::Vector2f scrollOffset)
{
    std::srand(std::time(NULL));

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