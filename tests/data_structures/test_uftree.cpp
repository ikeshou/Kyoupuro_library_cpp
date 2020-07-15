#include <gtest/gtest.h>
#include "all.h"
#include "data_structures/uftree.h"
#include "others/randint.h"


/**
 * 1 <= size <= M なるランダムな人数の個別グループを Iteration 回生成。
 * 毎回 Iteration 回だけ適当に選んだ 2 人を同一グループにまとめることを行い、ナイーブな手法と結果を照らし合わせるストレステストを行う。
 */
TEST(test_uftree, is_same_method) {
    i32 Iteration = 100;
    i32 M = 100;    // size の最大値
    for (i32 i = 0; i < Iteration; ++i) {
        i32 size = randint(1, M);
        VI naive_grouping(size, 0);
        iota(naive_grouping.begin(), naive_grouping.end(), 0);
        UFtree uf(size);
        for (i32 j = 0; j < Iteration; ++j) {
            // 適当に選んだ a, b を同一のグループにまとめる
            i32 a, b, group_a, group_b;
            a = randint(0, size - 1);
            b = randint(0, size - 1);
            group_a = naive_grouping[a];
            group_b = naive_grouping[b];
            EXPECT_EQ(group_a == group_b, uf.is_same(a, b));
            EXPECT_EQ(group_a != group_b, uf.unite(a, b));
            // naive_grouping の方は a のグループを全員 b のグループにする
            for (i32 k = 0; k < size; ++k) {
                if (naive_grouping[k] == group_a) naive_grouping[k] = group_b;
            }
        }
    }
}


/**
 * 1 <= size <= M なるランダムな人数の個別グループを Iteration 回生成。
 * 毎回 Iteration 回だけ適当に選んだ 2 人を同一グループにまとめることを行い、ナイーブな手法と結果を照らし合わせるストレステストを行う。
 */
TEST(test_uftree, akin_num_method) {
    i32 Iteration = 100;
    i32 M = 100;    // size の最大値
    for (i32 i = 0; i < Iteration; ++i) {
        i32 size = randint(1, M);
        VI naive_grouping(size, 0);
        iota(naive_grouping.begin(), naive_grouping.end(), 0);
        UFtree uf(size);
        for (i32 j = 0; j < Iteration; ++j) {
            // 適当に選んだ a, b を同一のグループにまとめる
            i32 a, b, group_a, group_b;
            a = randint(0, size - 1);
            b = randint(0, size - 1);
            group_a = naive_grouping[a];
            group_b = naive_grouping[b];
            uf.unite(a, b);
            // naive_grouping の方は a のグループを全員 b のグループにする
            for (i32 k = 0; k < size; ++k) {
                if (naive_grouping[k] == group_a) naive_grouping[k] = group_b;
            }            
        }
        for (i32 j = 0; j < size; ++j) {
            EXPECT_EQ(count(naive_grouping.begin(), naive_grouping.end(), naive_grouping[j]), uf.akin_num(j));
        }
    }
}