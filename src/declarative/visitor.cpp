#include "declarative/visitor.hpp"
#include "declarative/ui/component.hpp"
#include "declarative/ui/container.hpp"

declarative::DeclarativeElement& declarative::Visitor::operator()(Component& c) {
    return c;
}

declarative::DeclarativeElement& declarative::Visitor::operator()(Container& c) {
    return c;
}