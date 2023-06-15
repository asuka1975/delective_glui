#include "declarative/component.hpp"
#include "declarative/declarative_element.hpp"
#include <declarative/container.hpp>
#include <initializer_list>
#include <variant>

#include "declarative/visitor.hpp"

using namespace declarative;

Container::Container(std::initializer_list<std::variant<Container, Component>> args) : raw_elements(args.begin(), args.end()) {
    elements.reserve(raw_elements.size());
    for(auto& elem : raw_elements) {
        elements.emplace_back(std::visit(Visitor{}, elem));
    }

}