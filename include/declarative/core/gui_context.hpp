#ifndef DECLARATIVE_UI_DECLARATIVE_GUI_CONTEXT_HPP
#define DECLARATIVE_UI_DECLARATIVE_GUI_CONTEXT_HPP

#include <functional>
#include <list>
#include <any>
#include <type_traits>
#include <utility>
#include <variant>

namespace declarative {
    class GuiContext {
    public:
        template <class T>
        using StateDispatchAction = std::pair<T, std::function<void(T)>>;
        template <class T>
        auto useState(T t = T{}) -> std::enable_if_t<std::is_default_constructible_v<T>, StateDispatchAction<T>> {
            return _useState(t);
        }
        template <class T>
        auto useState(T t) -> std::enable_if_t<!std::is_default_constructible_v<T>, StateDispatchAction<T>> {
            return _useState(t);
        }
        void refresh();
    private:
        template <class T>
        StateDispatchAction<T> _useState(T t) {
            if(std::next(prevStatesIterator) == prevStates.end()) {
                prevStates.push_back(t);
                nextStates.push_back(t);
                prevStatesIterator = std::prev(prevStates.end());
                nextStatesIterator = std::prev(nextStates.end());
            } else {
                nextStatesIterator++;
                prevStatesIterator++;
            }
            auto f = [next=this->nextStatesIterator, prev=this->prevStatesIterator](T t) {
                *next = t;
            };
            return std::make_pair(*prevStatesIterator, f);
        }
        std::list<std::any> prevStates;
        std::list<std::any> nextStates;
        std::list<std::any>::iterator prevStatesIterator;
        std::list<std::any>::iterator nextStatesIterator;
    };
}

#endif