#include "declarative/visitor.hpp"
#include "declarative/component.hpp"

declarative::DeclarativeElement& declarative::Visitor::operator()(Component& c) {
    return c;
}

declarative::DeclarativeElement& declarative::Visitor::operator()(Container& c) {
    return c;
}