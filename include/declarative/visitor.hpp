#ifndef DECLARATIVE_UI_DECLARATIVE_VISITOR_HPP
#define DECLARATIVE_UI_DECLARATIVE_VISITOR_HPP

#include "declarative/component.hpp"
#include "declarative/container.hpp"
#include "declarative/declarative_element.hpp"

namespace declarative {
    struct Visitor {
        DeclarativeElement& operator()(Component& c);
        DeclarativeElement& operator()(Container& c);
    };
}

#endif