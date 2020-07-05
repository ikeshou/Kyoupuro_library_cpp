#include "all.h"
#include "number_theory/prime.h"


/**
 * O(√N) で素数判定を行う
 */
bool is_prime(i64 num) {
    if (num < 1) {
        throw domain_error("is_prime(): argument should be >= 1.");
    }
    if (num == 2) return true;
    if (num == 1 || num % 2 == 0) return false;
    for (i64 i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}



/**
 * O(√N) で約数列挙を行う
 */
VL enum_divisor(i64 num) {
    if (num < 1) {
        throw domain_error("enum_divisor(): argument should be >= 1.");
    }
    VL divisor_small;
    VL divisor_large;
    for (i64 i = 1; i * i <= num; ++i) {
        if (num % i == 0) {
            divisor_small.push_back(i);
            if (i * i != num) {
                divisor_large.push_back(num / i);
            }
        }
    }
    divisor_small.insert(divisor_small.end(), divisor_large.rbegin(), divisor_large.rend());
    return divisor_small;
}


/**
 * エラトステネスの篩
 * O(NlglgN) で num までの素数判定テーブルを作る
 */
Eratos::Eratos(i64 num) :table_max(num), table(VB(num + 1, true)){
    if (num < 1) {
        throw domain_error("Eratos.Eratos(): argument should be >= 1.");
    }
    table[0] = false;
    table[1] = false;
    for (i64 i = 2; i * i <= num; ++i) {
        if (table[i]) {
            for (i64 j = i * i; j <= num; j += i) {
                table[j] = false;
            }
        }
    }
}

bool Eratos::is_prime(i64 num) {
    if (num < 1 || num > table_max) {
        throw domain_error("Eratos.is_prime(): argument should be 1 <= x <= table_max.");
    }
    return table[num];
}


unordered_map<i64, i64> Eratos::prime_factorize(i64 num) {
    if (num < 1 || (table_max + 1) * (table_max + 1) <= num) {
        throw domain_error("Eratos.prime_factorize(): argument should be 1 <= x <= √table_max ");
    }
    unordered_map<i64, i64> factorized_dict;
    for (i64 i = 2; i * i <= num; ++i) {
        if (num == 1) break;
        if (is_prime(i) && num % i == 0) {
            // 小さい素数から順にできるだけ割っていく
            i64 cnt = 0;
            while (num % i == 0) {
                num /= i;
                ++cnt;
            }
            factorized_dict[i] = cnt;
        }
    }
    // 最後は 1 or √n より大きい素数
    if (num != 1) factorized_dict[num] = 1;
    return factorized_dict;
}