//
// Created by marcel on 10/15/17.
//
/*
 *  Distributed under the Boost Software License, Version 1.0. (See accompanying
 *  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef CATCH_THEN_H
#define CATCH_THEN_H

#include <utility>
#include <optional>

template< typename F>
struct ThenImpl{
    F f;
    constexpr explicit ThenImpl(F func):f(func){}

    template<typename T>
    constexpr auto operator()(std::optional<T>&& opt_value)const-> typename std::enable_if<!std::is_void<decltype(f(std::forward<decltype(opt_value.value())>(opt_value.value())))>::value,std::optional<decltype(f(std::forward<decltype(opt_value.value())>(opt_value.value())))>>::type
    {
        if(opt_value.has_value())
        {
            return f(std::forward<decltype(opt_value.value())>(opt_value.value()));
        }

        return std::nullopt;
    }

    template<typename T>
    constexpr auto operator()(std::optional<T>&& opt_value)const-> typename std::enable_if<std::is_void<decltype(f(std::forward<decltype(opt_value.value())>(opt_value.value())))>::value,void>::type
    {
        if(opt_value.has_value()) f(std::forward<decltype(opt_value.value())>(opt_value.value()));
    }

};

template<typename F>
constexpr auto Then(F&& f)
{
   return ThenImpl<F>(std::forward<F>(f));
}

#endif //CATCH_THEN_H
