#include <gtest/gtest.h>
#include "declarative/component.hpp"
#include "declarative/container.hpp"
#include "declarative_ui.hpp"

namespace {
    TEST(create_test, test1) {
        declarative::Container c {
            declarative::Component {},
            declarative::Container {
                declarative::Component {},
                declarative::Component {},
                declarative::Component {},
                declarative::Component {},
            },
            declarative::Component {}
        };

        ASSERT_FALSE(true);
    }
}