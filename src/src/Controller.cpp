#include <Controller.hpp>

#include <ctime>
#include <cstdlib>
#include <iostream>


namespace Control {

void TetraminoController::start()
{
    std::cout << "Choose one type: I, J, L, O, S, T, Z\n";
    char letter;
    std::cin >> letter;

    if(letter == 'q')
        exit(0);

    Mechanic::Drawer field; //
    field.setupWinSettings();
    field.setupObjTextures();
    field.madeFigure(letter);
    events(field);

}

void TetraminoController::events(Mechanic::Drawer& field)
{
        field.render();
}

}
