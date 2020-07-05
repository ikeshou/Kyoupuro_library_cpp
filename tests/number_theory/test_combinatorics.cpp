#include <gtest/gtest.h>
#include "all.h"
#include "number_theory/combinatorics.h"
#include "others/randint.h"


TEST(test_pascal, comb_method) {
    Pascal p(15);
    VL factorial(16, 1);
    for (i32 i = 2; i < (i32)factorial.size(); ++i) factorial[i] = factorial[i-1] * i;
    for (i32 i = 0; i <= 15; ++i) {
        for (i32 j = 0; j <= i; ++j) {
            i64 expected = (factorial[i] / factorial[j]) / factorial[i-j];
            debug(i);
            debug(j);
            debug(expected);
            EXPECT_EQ(expected, p.comb(i, j));
        }
    }
}