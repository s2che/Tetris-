#ifndef USERINTERFACE_HPP
#define USERINTERFACE_HPP

#include <Drawer.hpp>

namespace Control {

class IConroller {
    virtual void start() = 0;
    virtual void events(Mechanic::Drawer&) = 0;
};

}

#endif // USERINTERFACE_HPP
