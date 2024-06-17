#include "Factory.h"

//Create a GameObject instance based on the provided name.
std::unique_ptr<GameObjects> Factory::create(const std::string& name)
{
	auto it = getMap().find(name);
	if (it == getMap().end())
		return nullptr;
	return it->second();
}

//Register a factory function for creating a GameObject by name.
bool Factory::registerit(const std::string& name, std::unique_ptr<GameObjects>(*f)())
{
	getMap().emplace(name, f);
	return true;
}

sf::VertexArray Factory::createDiamond(const std::string& name)
{
    int numCoins = 25; // Number of coins in the diamond shape (adjust as needed)
    sf::VertexArray vertexArray;
    vertexArray.resize(numCoins);

    // Calculate positions for each coin in the diamond shape
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            int index = i * 5 + j; // Compute index in the vertex array
            sf::Vector2f position(100.f + i * 50.f - j * 25.f, 100.f + j * 50.f);
            vertexArray[index].position = position;

            // Update the sprite position and texture
            auto coin = std::make_unique<Coin>();
            coin->updateSprite(position, &Resources::instance().getObjectTexture(0));

            // Add the created coin to the map
            //getMap().emplace(name, std::move(coin));
        }
    }
    return vertexArray;
}

sf::VertexArray Factory::createRectangle(const std::string& name)
{
    int numCoins = 20; // Number of coins in the rectangle shape (adjust as needed)
    sf::VertexArray vertexArray;
    vertexArray.resize(numCoins);

    // Example: Creating a rectangle shape of coins
    float startX = 100.f;
    float startY = 100.f;
    float width = 200.f;
    float height = 100.f;
    int index = 0;

    for (float x = startX; x < startX + width; x += width / 4.f) 
    {
        for (float y = startY; y < startY + height; y += height / 5.f) 
        {
            sf::Vector2f position(x, y);
            vertexArray[index].position = position;
            // Update the sprite position and texture
            auto coin = std::make_unique<Coin>();
            coin->updateSprite(position, &Resources::instance().getObjectTexture(0));

            // Add the created coin to the map
            //getMap().emplace(name, std::move(coin));
            ++index;
        }
    }
    return vertexArray;
}

sf::VertexArray Factory::createTriangle(const std::string& name)
{
    int numCoins = 10; // Number of coins in the triangle shape (adjust as needed)
    sf::VertexArray vertexArray;
    vertexArray.resize(numCoins);

    // Example: Creating a triangle shape of coins
    float startX = 100.f;
    float startY = 100.f;
    float base = 200.f;
    float height = 200.f;
    int index = 0;

    for (float y = startY; y < startY + height; y += height / 5.f) 
    {
        for (float x = startX; x < startX + base * (1 - (y - startY) / height); x += base / (5.f - (y - startY) / (height / 5.f))) 
        {
            sf::Vector2f position(x, y);
            vertexArray[index].position = position;
            // Update the sprite position and texture
            auto coin = std::make_unique<Coin>();
            coin->updateSprite(position, &Resources::instance().getObjectTexture(0));

            // Add the created coin to the map
            //getMap().emplace(name, std::move(coin));
            ++index;
        }
    }
    return vertexArray;
}

sf::VertexArray Factory::createCircle(const std::string& name)
{
    int numCoins = 50; // Number of coins in the circle shape (adjust as needed)
    sf::VertexArray vertexArray;
    vertexArray.resize(numCoins);

    // Example: Creating a circle shape of coins
    float centerX = 300.f;
    float centerY = 300.f;
    float radius = 150.f;
    float angleIncrement = 360.f / numCoins;
    int index = 0;

    for (float angle = 0.f; angle < 360.f; angle += angleIncrement) 
    {
        float x = centerX + std::cos(angle * 3.14f / 180.f) * radius;
        float y = centerY + std::sin(angle * 3.14f / 180.f) * radius;
        sf::Vector2f position(x, y);
        vertexArray[index].position = position;
        // Update the sprite position and texture
        auto coin = std::make_unique<Coin>();
        coin->updateSprite(position, &Resources::instance().getObjectTexture(0));

        // Add the created coin to the map
        //getMap().emplace(name, std::move(coin));
        ++index;
    }
    return vertexArray;
}

sf::VertexArray Factory::createHeart(const std::string& name)
{
    int numCoins = 30; // Number of coins in the heart shape (adjust as needed)
    sf::VertexArray vertexArray;
    vertexArray.resize(numCoins);

    float centerX = 400.f;
    float centerY = 300.f;
    float scale = 150.f; // Scale factor for adjusting the heart size
    float angle = 0.f;
    float angleIncrement = 2.f * 3.14159265358979323846f / numCoins; // Angle increment for each coin
    int index = 0;

    for (float t = 0.f; t < 2.f * 3.14159265358979323846f; t += angleIncrement) 
    {
        float x = scale * (16.f * std::pow(std::sin(t), 3.f));
        float y = -scale * (13.f * std::cos(t) - 5.f * std::cos(2.f * t) - 2.f * std::cos(3.f * t) - std::cos(4.f * t));
        sf::Vector2f position(centerX + x, centerY + y);
        vertexArray[index].position = position;
        // Update the sprite position and texture
        auto coin = std::make_unique<Coin>();
        coin->updateSprite(position, &Resources::instance().getObjectTexture(0));

        // Add the created coin to the map
        //getMap().emplace(name, std::move(coin));
        ++index;
    }
    return vertexArray;
}
