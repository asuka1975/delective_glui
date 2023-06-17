#include "declarative/visitor.hpp"
#include "declarative/core/component.hpp"
#include "declarative/core/container.hpp"

declarative::DeclarativeElement& declarative::Visitor::operator()(Component& c) {
    return c;
}

declarative::DeclarativeElement& declarative::Visitor::operator()(Container& c) {
    return c;
}