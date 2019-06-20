//
//  fenwick_tree.cpp
//  AlgoManual
//
//  Created by LSH on 01/02/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

/**
* Binary Indexed Tree (BIT) 펜윅트리
*/
#include <stdio.h>
#include <algorithm>
using namespace std;

const int N = 100;
typedef long long ll;
ll tree[N];

void update(ll x, ll val){
    while(x <= N){
        tree[x] += val;
        x += (x&-x);
    }
}

ll query(int x){
    ll sum = 0;
    while(x > 0){
        sum += tree[x];
        x -= (x&-x);
    }
    return sum;
}

void go(ll x, ll y, ll val){
    if(x <= y) {
        update(x, val);
        update(y+1, -val);
    } else{
        update(1, val);
        update(x+1, -val);
        update(y, val);
    }
}

