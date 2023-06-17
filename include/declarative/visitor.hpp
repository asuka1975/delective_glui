#ifndef DECLARATIVE_UI_DECLARATIVE_VISITOR_HPP
#define DECLARATIVE_UI_DECLARATIVE_VISITOR_HPP

#include "declarative/core/declarative_element.hpp"
#include "declarative/types.hpp"
#include <variant>

namespace declarative {
    class Component;
    class Container;
    struct Visitor {
        DeclarativeElement& operator()(Component& c);
        DeclarativeElement& operator()(Container& c);
    };
}

#endif