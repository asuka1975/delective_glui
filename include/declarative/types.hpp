#ifndef DECLARATIVE_UI_DECLARATIVE_TYPES_HPP
#define DECLARATIVE_UI_DECLARATIVE_TYPES_HPP

#include <variant>

namespace declarative {
    class Container;
    class Component;

    using Element = std::variant<Container, Component>;
}

#endif