#include <iostream>
#include "declarative/core/component.hpp"
#include "declarative/core/gui_context.hpp"
#include "declarative/types.hpp"
#include "declarative_ui.hpp"

#include <GLFW/glfw3.h>
#include <stdexcept>

declarative::Element SampleComponent(declarative::GuiContext& ctx) {
    auto [value, setValue] = ctx.useState(1);

    return declarative::Container {
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
        }
    };
}

int main() {
    if(glfwInit() == GLFW_FALSE) {
        throw std::runtime_error("failed to initialize GLFW");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

    auto window = glfwCreateWindow(1000, 1000, "", nullptr, nullptr);
    if(window == nullptr) {
        throw std::runtime_error("failed create GLFWwindow");
    }

    while(glfwWindowShouldClose(window) == GLFW_FALSE) {
        glfwSwapBuffers(window);
        glfwWaitEvents();
    }
}