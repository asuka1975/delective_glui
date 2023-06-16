#ifndef DECLARATIVE_UI_DECLARATIVE_CONTAINER_HPP
#define DECLARATIVE_UI_DECLARATIVE_CONTAINER_HPP

#include "declarative/component.hpp"
#include "declarative/declarative_element.hpp"

#include <functional>
#include <initializer_list>
#include <utility>
#include <variant>
#include <vector>
#include "declarative/visitor.hpp"

namespace declarative {
    class Container : public virtual DeclarativeElement {
    public:
        ~Container() override = default;
        Container(const Container&);
        Container(Container&&) = default;
        Container& operator=(const Container&);
        Container& operator=(Container&&) = default;

        explicit Container(std::initializer_list<Element>);
    private:
        std::vector<Element> raw_elements;
        std::vector<std::reference_wrapper<DeclarativeElement>> elements;
    };
}

#endif