//
// Created by marcel on 11/1/17.
//
#include "catch.hpp"
#include "MultiPredicate.h"

namespace MultiPredicateTest {
    struct Data
    {
        Data(int d1, int d2) :d1(d1), d2(d2) {}
        int d1;
        int d2;
    };
    bool operator==(Data const& data1, Data const& data2){
        return data1.d1 == data2.d1 && data1.d2 == data2.d2;
    }
    auto D1LessThan(int i) {
        return [i](Data const& data) {
            return data.d1 < i;
        };
    }
    auto D2Greater(int i) {
        return [i](Data const& data) {
            return data.d2 > i;
        };
    }

    TEST_CASE("filter") {
        std::vector<Data> input = {{1,2},{3,4},{5,6},{8,9},{10,11},{12,13},{14,14}};
        std::vector<Data> expected = {{5,6},{8,9},{10,11},{12,13}};

        auto new_end = std::remove_if(std::begin(input),
                                      std::end(input),
                                      MultiOr(D1LessThan(5),
                                              D2Greater(13)));
        input.erase(new_end, std::end(input));
        REQUIRE(expected == input);
    }

}
