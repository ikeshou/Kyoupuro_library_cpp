#include "all.h"
#include "number_theory/combinatorics.h"


/**
 * O(N^2) で 0C0 ... nCn までのコンビネーションを計算したパスカルの三角形を構築する
 * pascal[i][j] = iCj を表す。
 */
Pascal::Pascal(i64 num) :n(num), pascal(VVL(num + 1, VL())) {
    for (i64 i = 0; i < n + 1; ++i) {
        for (i64 j = 0; j < i + 1; ++j) {
            // iC0, 0Cj は 1. 初期化をかねて記入しておく
            pascal[i].push_back(1);
        }
    }
    for (i64 i = 2; i < n + 1; ++i) {
        // i 段目。0, 1 段目はすでに 1 で埋まっている
        for (i64 j = 1; j < i; ++j) {
            // iCj = i-1Cj-1 + i-1Cj
            pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
        }
    }
}

/**
 * O(1) で aCb を計算する
 */
i64 Pascal::comb(i64 a, i64 b) {
    if (a < b) throw invalid_argument("argument should be a >= b.");
    if (a > n) throw domain_error("argument exceeds pascal's triangle size.");
    return pascal[a][b];
}