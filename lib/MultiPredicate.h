//
// Created by marcel on 11/1/17.
//
/*
 *  Distributed under the Boost Software License, Version 1.0. (See accompanying
 *  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef CATCH_MULTIPREDICATE_H
#define CATCH_MULTIPREDICATE_H

#include <tuple>

template<typename BinaryOp , typename ... Predicates>
class MultiPredImpl{
    std::tuple<Predicates ...> preds_tuple;
    BinaryOp binary_op;
    template<std::size_t> struct int2type {};
    template<size_t N, typename T>
    constexpr auto apply(int2type<N>, T&& t)const {
        return binary_op(std::get<N>(preds_tuple)(std::forward<T>(t)),
                         apply(int2type<N - 1>(), std::forward<T>(t)));
    }

    template<typename T>
    constexpr auto apply(int2type<0>, T&&  t)const {
        return std::get<0>(preds_tuple)(std::forward<T>(t));
    }
public:
    constexpr MultiPredImpl(BinaryOp&& op, Predicates&& ... preds)
    : preds_tuple(std::forward_as_tuple(preds ...))
     ,binary_op(std::forward<BinaryOp>(op)){}

    template<typename T>
    constexpr auto operator()(T&& t)const {
        return apply(int2type<sizeof ... (Predicates)-1>(), std::forward<T>(t));
    }

};

template<typename BinaryOp , typename ... Predicates>
constexpr auto MultiPred(BinaryOp &&op, Predicates &&... preds){
    return MultiPredImpl<BinaryOp, Predicates ...>(std::forward<BinaryOp>(op), std::forward<Predicates>(preds) ...);
}

#endif //CATCH_MULTIPREDICATE_H
