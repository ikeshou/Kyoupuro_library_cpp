#include <gtest/gtest.h>
#include "all.h"
#include "number_theory/fibonacci.h"
#include "others/randint.h"


TEST(test_fibonacci, first_16) {
    VI fibo = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987};
    for (i32 i = 0; i < (i32)fibo.size(); ++i) {
        EXPECT_EQ(fibonacci(i), *(fibo.begin() + i));
    }
}