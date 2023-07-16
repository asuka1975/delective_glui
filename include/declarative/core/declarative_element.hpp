#ifndef DECLARATIVE_UI_DECLARATIVE_DECLARATIVE_ELEMENT_HPP
#define DECLARATIVE_UI_DECLARATIVE_DECLARATIVE_ELEMENT_HPP

#include "declarative/style.hpp"
namespace declarative {
    struct DeclarativeElement {
        virtual ~DeclarativeElement() = default;
        virtual const Style& style() const = 0;
    };
}

#endif