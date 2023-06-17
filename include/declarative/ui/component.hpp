#ifndef DECLARATIVE_UI_DECLARATIVE_COMPONENT_HPP
#define DECLARATIVE_UI_DECLARATIVE_COMPONENT_HPP

#include "declarative/ui/declarative_element.hpp"

namespace declarative {
    class Component : public virtual DeclarativeElement {
    public:
        ~Component() override = default;
        Component() = default;
    };
}

#endif