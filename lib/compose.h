//
// Created by marcel on 8/19/17.
//

#ifndef CATCH_COMPOSE_H
#define CATCH_COMPOSE_H

#include <tuple>

// this is taken from
//
// https://codereview.stackexchange.com/questions/63841/c-function-composition
//
// and changed like the reviewer suggested.
// Functions are composed from left to right:
//
// auto return_value_from_f3 = compose(f1, f2, f3)(arguments_for_f1)
//
// is the same as:
//
// auto return_value_from_f3 = f3(f2(f1(arguments_for_f1)))
//
template<typename ... Fs>
struct compose_impl
{
    compose_impl(Fs&& ... fs) : functionTuple(std::forward_as_tuple(fs ...)) {}

    template<std::size_t> struct int2type{};

    template<size_t N, typename ... Ts>
    auto apply(int2type<N>, Ts&& ... ts)
    {
        return std::get<N>(functionTuple)(apply(int2type<N-1>(),std::forward<Ts>(ts)...));
    }

    static const size_t size = sizeof ... (Fs);
    template<typename ... Ts>
    auto apply(int2type<0>, Ts&& ... ts)
    {
        return std::get<0>(functionTuple)(std::forward<Ts>(ts)...);
    }

    template<typename ... Ts>
    auto operator()(Ts&& ... ts)
    {
        return apply(int2type<sizeof ... (Fs) - 1>(), std::forward<Ts>(ts)...);
    }

    std::tuple<Fs ...> functionTuple;
};

template<typename ... Fs>
auto compose(Fs&& ... fs)
{
    return compose_impl<Fs ...>(std::forward<Fs>(fs) ...);
}

#endif //CATCH_COMPOSE_H
