//
// Created by marcel on 11/1/17.
//

#ifndef CATCH_MULTIPREDICATE_H
#define CATCH_MULTIPREDICATE_H

#include <tuple>

template<typename ... Predicates>
class MultiOrImpl{
    std::tuple<Predicates ...> preds_tuple;
    template<std::size_t> struct int2type {};
    template<size_t N, typename T>
    auto apply(int2type<N>, T&& t)const {
        return std::get<N>(preds_tuple)(t) ||  apply(int2type<N - 1>(), t);
    }

    template<typename T>
    auto apply(int2type<0>, T&&  t)const {
        return std::get<0>(preds_tuple)(t);
    }
public:
    MultiOrImpl(Predicates&& ... preds)
    : preds_tuple(preds ...){}

    template<typename T>
    auto operator()(T&& t)const {
        return apply(int2type<sizeof ... (Predicates)-1>(), t);
    }

};

template<typename ... Predicates>
auto MultiOr(Predicates&& ... preds){
    return MultiOrImpl<Predicates ...>(std::forward<Predicates>(preds) ...);
}

#endif //CATCH_MULTIPREDICATE_H
