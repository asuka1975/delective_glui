#ifndef DECLARATIVE_UI_DECLARATIVE_STYLE_HPP
#define DECLARATIVE_UI_DECLARATIVE_STYLE_HPP

#include "declarative/color.hpp"
namespace declarative {
    struct Style {
        int width = 100;
        int height = 100;
        Color background_color = {};
    };
}

#endif