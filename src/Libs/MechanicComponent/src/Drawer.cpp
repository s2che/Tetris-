#include <Drawer.hpp>

namespace Mechanic {

void Drawer::render()
{
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed                  ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) ||
                sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                closeWindow();
        }

        for (int i = 0; i < 4; i++)
        {
            std::array<int, 4> thisFigure = figures[0].getForm();
            cubes[i].x = thisFigure[i] % 2;
            cubes[i].y = thisFigure[i] / 2;
        }

        window.clear(sf::Color::White);

        for (int i = 0; i < 4; i++)
        {
            sprite.setPosition(cubes[i].x * 20, cubes[i].y * 20);
            sprite.setTextureRect(sf::IntRect(figures[0].getColour() * 20, 0, 20, 20));
            sprite.move(50, 0);
            window.draw(sprite);
        }

        window.display();
    }
}

std::shared_ptr<Geometry::Tetramino> Drawer::madeFigure(char letter)
{
    Geometry::Tetramino figure(letter);
    figures.push_back(figure);
    return std::make_shared<Geometry::Tetramino>(figure);
}

void Drawer::setupWinSettings(int width, int height, std::string title)
{
    window.create(sf::VideoMode(width, height), title);
}

void Drawer::setupObjTextures(std::string textureFPath)
{
    texture.loadFromFile(textureFPath);
    texture.setSmooth(true);

    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 20, 20));
}

void Drawer::closeWindow()
{
    window.close();
}

}
