#include <Tetramino.hpp>

namespace Geometry {

Tetramino::Tetramino(char letter)
{
    switch (letter) { //enum
    case 'I':
        form[0] = 1;
        form[1] = 3;
        form[2] = 5;
        form[3] = 7;

        setColour(red);
        break;

    case 'J':
        form[0] = 3;
        form[1] = 5;
        form[2] = 7;
        form[3] = 6;

        setColour(orange);
        break;

    case 'L':
        form[0] = 2;
        form[1] = 3;
        form[2] = 5;
        form[3] = 7;

        setColour(yellow);
        break;

    case 'O':
        form[0] = 2;
        form[1] = 3;
        form[2] = 4;
        form[3] = 5;

        setColour(green);
        break;

    case 'S':
        form[0] = 2;
        form[1] = 4;
        form[2] = 5;
        form[3] = 7;

        setColour(turquoise);
        break;

    case 'T':
        form[0] = 3;
        form[1] = 5;
        form[2] = 4;
        form[3] = 7;

        setColour(blue);
        break;

    case 'Z':
        form[0] = 3;
        form[1] = 5;
        form[2] = 4;
        form[3] = 6;

        setColour(purple);
        break;

    default:
        throw;
    }

    srand(time(NULL));

    int bonus = rand()%10;
    if(bonus == 1)
        setColour(bonus);

}

void Tetramino::setColour(int type)
{
    colour = type;
}

int Tetramino::getColour()
{
    return colour;
}

std::array<int, 4> Geometry::Tetramino::getForm()
{
    return form;
}

}







