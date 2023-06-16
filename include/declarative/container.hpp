#ifndef DECLARATIVE_UI_DECLARATIVE_CONTAINER_HPP
#define DECLARATIVE_UI_DECLARATIVE_CONTAINER_HPP

#include "declarative/component.hpp"
#include "declarative/declarative_element.hpp"

#include <functional>
#include <initializer_list>
#include <variant>
#include <vector>

namespace declarative {
    class Container : public virtual DeclarativeElement {
    public:
        ~Container() override = default;
        explicit Container(std::initializer_list<std::variant<Container, Component>> args);
    private:
        std::vector<std::variant<Container, Component>> raw_elements;
        std::vector<std::reference_wrapper<DeclarativeElement>> elements;
    };
}

#endif