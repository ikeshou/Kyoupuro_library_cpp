#include <gtest/gtest.h>
#include "all.h"
#include "number_theory/euclid_gcd.h"
#include "others/randint.h"


TEST(test_euclid_gcd, random_case) {
    i32 Iteration = 1000;
    for (i32 i = 0; i < Iteration; ++i) {
        i32 a = randint(-100, 100);
        i32 b = randint(-100, 100);
        EXPECT_EQ(gcd(a, b), euclid_gcd(a, b));
    }
}


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