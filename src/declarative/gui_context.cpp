#include "declarative/core/gui_context.hpp"

namespace declarative {
    void GuiContext::refresh() {
        prevStates = nextStates;
    }
}
