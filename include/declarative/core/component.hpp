#ifndef DECLARATIVE_UI_DECLARATIVE_COMPONENT_HPP
#define DECLARATIVE_UI_DECLARATIVE_COMPONENT_HPP

#include "declarative/core/declarative_element.hpp"
#include "declarative/style.hpp"

namespace declarative {
    class Component : public virtual DeclarativeElement {
    public:
        ~Component() override = default;
        template <class... TArgs>
        Component(Style style = Style {}) : m_style(style) {}
        const Style& style() const override;
    private:
        Style m_style;
    };
}

#endif