#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <UserInterface.hpp>

namespace Control {

class TetraminoController : public IConroller
{
public:
    void start() override;

private:
    void events(Mechanic::Drawer& field) override; // const sharedPtr (const - для неизм членов классса)
};

}
#endif // CONTROLLER_HPP
