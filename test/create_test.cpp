#include <gtest/gtest.h>
#include "declarative/ui/component.hpp"
#include "declarative/ui/container.hpp"
#include "declarative/style.hpp"
#include "declarative_ui.hpp"

namespace {
    TEST(create_test, test1) {
        declarative::Container c {
            {
                declarative::Component {},
                declarative::Container {
                    {
                        declarative::Component {},
                        declarative::Component {},
                        declarative::Component {},
                        declarative::Component {},
                    },
                    declarative::Style {
                        .width = 200,
                        .height = 200
                    }
                },
                declarative::Component {}
            },
            declarative::Style {
                .width = 100
            }
        };

        ASSERT_FALSE(true);
    }
}