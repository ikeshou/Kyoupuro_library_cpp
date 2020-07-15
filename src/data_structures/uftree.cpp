#include "all.h"
#include "data_structures/uftree.h"


/**
 * O(n) で 0 ~ num_of_elm - 1 の数字で表される個別グループを管理する UFtree を作成する
 */
UFtree::UFtree(i64 num_of_elm)
    :num_of_elm(num_of_elm),
     par(num_of_elm, 0), 
     rank(num_of_elm, 0), 
     group_size(num_of_elm, 1)
{
    for (i64 i = 0; i < num_of_elm; ++i) par[i] = i;   
}


/**
 *  O(α(n)) で x の属するグループ番号を求める
 */
i64 UFtree::find_root(i64 x) {
    i64 parent = par[x];
    if (parent == x) {
        return x;
    } else {
        i64 root = find_root(parent);
        // 経路圧縮
        par[x] = root;
        return root;
    }
}


/**
 *  O(α(n)) で x と y が同じグループに存在するか判定する
 */
bool UFtree::is_same(i64 x, i64 y) {
    return (find_root(x) == find_root(y));
}


/**
 *  O(α(n)) で x と y の所属するグループを統合する。統合を新たに行ったかの真偽値を返す。
 */
bool UFtree::unite(i64 x, i64 y) {
    i64 shallow = find_root(x);
    i64 deep = find_root(y);
    if (rank[shallow] > rank[deep]) swap(shallow, deep);

    if (shallow == deep) {
        // そもそも同一グループのとき
        return false;
    } else {
        // グループが異なるので unite
        par[shallow] = deep;
        group_size[deep] += group_size[shallow];
        // 深さが等しかったときはつけ加えられた側の rank をインクリメントする
        if (rank[shallow] == rank[deep]) rank[deep]++;
        return true;
    }
}


/**
 * O(α(n)) で x の属するグループのサイズ（所属メンバー数）を計算する
 */
i64 UFtree::akin_num(i64 x) {
    i64 root = find_root(x);
    return group_size[root];
}
