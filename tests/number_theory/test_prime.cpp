#include <gtest/gtest.h>
#include "all.h"
#include "number_theory/prime.h"
#include "others/randint.h"


/**
 * Iteration 回 1 <= num <= 1000 なる整数を選択し、is_prime の結果とナイーブに素数判定を行った結果を比較するテストを行う。
 */
TEST(test_is_prime, random_case) {
    i32 Iteration = 100;
    for (i32 i = 0; i < Iteration; ++i) {
        i32 num = randint(1, 1000);
        bool expected = (num == 1) ? false : true;
        for (i32 j = 2; j < num; ++j) {
            if (num % j == 0) {
                expected = false;
                break;
            }
        }
        EXPECT_EQ(expected, is_prime(num));
    }
}


/**
 * Iteration 回 1 <= num <= 1000 なる整数を選択し、enum_divisor の結果とナイーブに列挙した結果を比較するテストを行う。
 */
TEST(test_enum_divisor, random_case) {
    i32 Iteration = 100;
    for (i32 i = 0; i < Iteration; ++i) {
        i32 num = randint(1, 1000);
        VL divisor;
        for (i32 j = 1; j <= num; ++j) {
            if (num % j == 0) divisor.push_back(j);
        }
        EXPECT_EQ(divisor, enum_divisor(num));
    }
}


/**
 * 50 以下の数について素数判定が正しく動くかチェックする。
 */
TEST(test_eratos, is_prime_method) {
    VI p_list = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    Eratos e(50);
    for (i32 i = 1; i <= 50; ++i) {
        EXPECT_EQ(find(p_list.begin(), p_list.end(), i) != p_list.end(), e.is_prime(i));
    }
}


/**
 * 50 以下の数について素因数分解が正しく動くかチェックする。
 */
TEST(test_eratos, prime_factorize_method) {
    VI p_list = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    Eratos e(50);
    for (i32 i = 1; i < 51 * 51; ++i) {
        unordered_map<i64, i64> got = e.prime_factorize(i);
        unordered_map<i64, i64> expected;
        i32 target = i;
        i32 d = 2;
        while (target > 1) {
            while (target % d == 0) {
                target /= d;
                expected[d]++;
            }
            d++;
        }
        EXPECT_EQ(expected, got);
    }
}