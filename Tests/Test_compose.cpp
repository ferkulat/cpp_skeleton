//
// Created by marcel on 10/20/17.
//

#include <Then.h>
#include <compose.h>
#include <iostream>
#include "catch.hpp"


namespace ComposeTest{

    int Add10    (int i){ return i+10;}
    int DoubleIt (int i){ return i*2; }
    int DivideBy4(int i){ return i/4; }

    double DivideBy2(int i){return i/2.0;}

    constexpr auto const some_complex_function = compose(Add10,
                                                         DoubleIt,
                                                         DivideBy4);

    constexpr auto const some_even_more_complex_function = compose(some_complex_function, DivideBy2);

    TEST_CASE("Passing 4 results in 7") {
        REQUIRE(7 == some_complex_function(4));
    }
    TEST_CASE("Passing 4 results in 3.5") {
        REQUIRE(3.5 == some_even_more_complex_function(4));
    }
}

namespace ThenTest {
    int DoubleIt(int i){ return i*2; }
    int Square  (int i){ return i*i; }

    std::optional<int> IfUpToFour(int i){
        if (i < 5) {return i;}
        return std::nullopt;
    }

    template<typename T> void DoNothing(T &&t){}

    template<typename F=decltype(DoNothing<int>)>
    constexpr auto IfUpToFourOr(F f=DoNothing<int>){
        return [f](int i)->std::optional<int> {
            if (i < 5) return i;

            f(std::forward<int>(i));
            return std::nullopt;
        };
    }

    constexpr auto const  sfehler = [](int i){std::cout << "value " << i << " is out of range\n";};

    constexpr auto const DoubleAndSquareIfLessThan3 = compose(DoubleIt,
                                                              IfUpToFourOr(sfehler),
                                                              Then(Square));

    TEST_CASE("Passing 2 results in optional<int>(16)") {
        REQUIRE(std::optional<int>(16) == DoubleAndSquareIfLessThan3(2));
    }

    TEST_CASE("Passing 3 results in nothing ") {
        REQUIRE(std::optional<int>() == DoubleAndSquareIfLessThan3(3));
    }

}