#include <iostream>
#include "declarative_ui.hpp"

int main() {
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
    std::cout << "Hello, world" << std::endl;
}