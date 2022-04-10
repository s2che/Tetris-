#ifndef DRAWER_HPP
#define DRAWER_HPP

#include <Tetramino.hpp>

#include <SFML/Graphics.hpp>

#include <vector>
#include <memory>

namespace Mechanic {

struct Point{
    int x;
    int y;
};
//magic numbers

class Drawer
{
    //win
    sf::RenderWindow window;
    sf::Texture texture;
    sf::Sprite sprite;
    Point cubes[4];

    std::vector<Geometry::Tetramino> figures;

public:
    Drawer() = default;

    //window
    void setupWinSettings(int width = 160, int height = 160, std::string title = "Tetraminos");
    void setupObjTextures(std::string textureFPath = "/home/left/gitProjects/Tetramino/tetr.png");
    void render();
    void closeWindow();

    //figures
    std::shared_ptr<Geometry::Tetramino> madeFigure(char letter);
};

}

#endif // DRAWER_HPP
