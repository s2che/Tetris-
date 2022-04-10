#ifndef TETRAMINO_HPP
#define TETRAMINO_HPP

#include <array>

namespace Geometry {

enum ColoursType{
    red = 0,
    orange,
    yellow,
    green,
    turquoise,
    blue,
    purple,
    bonus = 7,
};

class Tetramino
{
    std::array<int, 4> form;
    int colour;

public:
    Tetramino(char letter);

    void setColour(int type);
    int getColour(void);

    std::array<int, 4> getForm(void);
};

}


#endif // TETRAMINO_HPP
