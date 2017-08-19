//
// Created by marcel on 8/19/17.
//

#ifndef CATCH_PIPEDFUNCTIONCALLS_H
#define CATCH_PIPEDFUNCTIONCALLS_H

#include <utility>

template<typename VALUE, typename FUNCTION>
auto operator|(VALUE&& value, FUNCTION fun)-> decltype(fun(std::forward<VALUE>(value)))
{
    return fun(std::forward<VALUE>(value));
}

#endif //CATCH_PIPEDFUNCTIONCALLS_H
