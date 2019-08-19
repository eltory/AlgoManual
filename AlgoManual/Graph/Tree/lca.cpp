//
//  lca.cpp
//  AlgoManual
//
//  Created by LSH on 01/02/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 100;
vector<vector<int>> adj;
bool vs[MAX];
int d[MAX], par[MAX][2*MAX];

int lca(int x, int y) {
    if (d[x] > d[y])
        swap(x, y);
    for (int i = 20; i >= 0; i--) {
        if (d[y] - d[x] >= (1 << i))
            y = par[y][i];
    }
    if (x == y)return x;
    for (int i = 20; i >= 0; i--) {
        if (par[x][i] != par[y][i]) {
            x = par[x][i];
            y = par[y][i];
        }
    }
    return par[x][0];
}

void dfs(int u,int dep) {
    vs[u] = true;
    d[u] = dep;
    for (int v : adj[u]) {
        if (vs[v])
            continue;
        par[v][0] = u;
        dfs(v, dep + 1);
    }
}
void f() {
    for (int j = 1; j < 21; j++) {
        for (int i = 1; i <= n; i++) {
            par[i][j] = par[par[i][j - 1]][j - 1];
        }
    }
}

