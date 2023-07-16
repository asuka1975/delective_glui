#include "declarative/core/component.hpp"
#include "declarative/core/declarative_element.hpp"
#include <declarative/core/container.hpp>
#include <initializer_list>
#include <iterator>
#include <variant>

#include "declarative/style.hpp"
#include "declarative/visitor.hpp"

using namespace declarative;


const Style& Component::style() const {
    return m_style;
}