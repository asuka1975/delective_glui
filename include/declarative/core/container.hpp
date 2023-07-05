#ifndef DECLARATIVE_UI_DECLARATIVE_CONTAINER_HPP
#define DECLARATIVE_UI_DECLARATIVE_CONTAINER_HPP

#include "declarative/core/component.hpp"
#include "declarative/core/declarative_element.hpp"

#include <functional>
#include <initializer_list>
#include <utility>
#include <variant>
#include <vector>
#include "declarative/style.hpp"
#include "declarative/types.hpp"
#include "declarative/visitor.hpp"

namespace declarative {
    class Container : public virtual DeclarativeElement {
    public:
        class ContainerArgument {
        public:
            template <class T>
            std::vector<Element> concat(std::vector<Element>&& v, T&& arg) {
                v.emplace_back(std::forward<T>(arg));
                return std::move(v);
            }

            template <class T, class... TArgs>
            std::vector<Element> concat(std::vector<Element>&& v, T&& arg1, TArgs&&... args) {
                v.emplace_back(std::forward<T>(arg1));
                return concat(std::move(v), std::forward<TArgs>(args)...);
            }

            template <class... TArgs>
            ContainerArgument(TArgs&&... args) : raw_elements(concat(std::vector<Element> {}, std::forward<TArgs>(args)...)) {
                elements.reserve(raw_elements.size());
                for(auto& elem : raw_elements) {
                    elements.emplace_back(std::visit(Visitor{}, elem));
                }
            }
        private:
            friend class Container;
            std::vector<Element> raw_elements;
            std::vector<std::reference_wrapper<DeclarativeElement>> elements;
        };
    public:
        ~Container() override = default;
        Container(const Container&) = delete;
        Container(Container&&) = default;
        Container& operator=(const Container&) = delete;
        Container& operator=(Container&&) = default;

        template <class... TArgs>
        Container(ContainerArgument args, Style = Style {}) : raw_elements(std::move(args.raw_elements)), elements(std::move(args.elements)) {}
    private:
        std::vector<Element> raw_elements;
        std::vector<std::reference_wrapper<DeclarativeElement>> elements;
    };
}

#endif