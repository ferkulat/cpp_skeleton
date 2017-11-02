//
// Created by marcel on 11/1/17.
//
#include "catch.hpp"
#include "MultiPredicate.h"
#include <functional>

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
                                      MultiPred(std::logical_or<bool>(),
                                                D1LessThan(5),
                                                D2Greater(13)));
        input.erase(new_end, std::end(input));
        REQUIRE(expected == input);
    }

    struct Res{
        float sulfur;
        float carbon;
        float price;
    };
    bool operator==(Res const& r1, Res const& r2){
        return (r1.sulfur - r2.sulfur) < 0.01 &&
                (r1.carbon - r2.carbon) < 0.01 &&
                (r1.price - r2.price) < 0.01;
    }
    auto ImpactSulfur(float impact){
        return [impact](Res const& res){ return 1.0/(res.sulfur*impact);};
    }
    auto ImpactCarbon(float impact){
        return [impact](Res const& res){ return res.carbon*impact;};
    }
    auto ImpactPrice(float impact){
        return [impact](Res const& res){ return 1.0/(res.price*impact);};
    }
    TEST_CASE("sort") {

        std::vector<Res> input = {{0.02, 0.4, 3.0}, {0.01, 0.4, 3.0}, {0.02, 0.3, 3.0}};
        std::vector<Res> expected = {{0.02, 0.3, 3.0},{0.02, 0.4, 3.0}, {0.01, 0.4, 3.0}, };
        auto const quality = MultiPred(std::multiplies<float>(),
                                       ImpactSulfur(2.0),
                                       ImpactCarbon(1.0),
                                       ImpactPrice(1.0));
        std::sort(std::begin(input), std::end(input), [quality](Res const& r1, Res const& r2){ return quality(r1) < quality(r2);});

        REQUIRE(expected == input);

    }
}
