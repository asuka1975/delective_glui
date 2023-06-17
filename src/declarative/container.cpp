#include "declarative/ui/component.hpp"
#include "declarative/ui/declarative_element.hpp"
#include <declarative/ui/container.hpp>
#include <initializer_list>
#include <iterator>
#include <variant>

#include "declarative/visitor.hpp"

using namespace declarative;

Container::Container(const Container& obj) : raw_elements(obj.raw_elements) {
    elements.reserve(raw_elements.size());
    for(auto& elem : raw_elements) {
        elements.emplace_back(std::visit(Visitor{}, elem));
    }
}

Container& Container::operator=(const Container& obj) {
    elements.clear();
    raw_elements = obj.raw_elements;

    elements.reserve(raw_elements.size());
    for(auto& elem : raw_elements) {
        elements.emplace_back(std::visit(Visitor{}, elem));
    }
    return *this;
}

Container::Container(std::initializer_list<Element> args, Style style) : raw_elements(args.begin(), args.end()) {
    elements.reserve(raw_elements.size());
    for(auto& elem : raw_elements) {
        elements.emplace_back(std::visit(Visitor{}, elem));
    }
}