#include <gtest/gtest.h>
#include "all.h"
#include "number_theory/euclid_gcd.h"
#include "others/randint.h"


/**
 * Iteration 回 a, b を生成し gcd を計算。std::gcd と結果を比較する。
 */
TEST(test_euclid_gcd, random_case) {
    i32 Iteration = 1000;
    for (i32 i = 0; i < Iteration; ++i) {
        i32 a = randint(-100, 100);
        i32 b = randint(-100, 100);
        EXPECT_EQ(gcd(a, b), euclid_gcd(a, b));
    }
}


/**
 * Iteration 回 a, b を生成し、ax + by = d (=gcd(a, b)) なる x, y, d を計算。
 * 実際に ax + by - d = 0 となるか確かめ、d を std::gcd と比較することで、この拡張ユークリッドの互除法を検証する。
 */
TEST(test_euclid_ext_gcd, random_case) {
    i32 Iteration = 1000;
    for (i32 i = 0; i < Iteration; ++i) {
        i32 a = randint(-100, 100);
        i32 b = randint(-100, 100);
        auto [x, y, d] = euclid_ext_gcd(a, b);
        EXPECT_EQ(0, a * x + b * y - d);
        EXPECT_EQ(gcd(a, b), d);
    }
}