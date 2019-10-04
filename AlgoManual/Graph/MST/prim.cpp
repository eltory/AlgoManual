//
//  prim.cpp
//  AlgoManual
//
//  Created by LSH on 07/07/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;
typedef pair<int, int> P;

int main() {
    int n, m;
    
    cin >> n >> m;
    
    vector <int> v(n + 1);
    vector <vector<P>> g(n + 1);
    priority_queue<P, vector<P>, greater<P>> pq;
    
    while (m--) {
        int x, y, cost;
        cin >> x >> y >> cost;
        g[x].push_back(P(cost, y));
        g[y].push_back(P(cost, x));
    }
    
    int s = 1;
    int ans = 0;
    
    for (int i = 0; i < n - 1; i++) {
        v[s] = 1;
        for (P x : g[s]) pq.push(x);
        while (v[pq.top().second]) pq.pop();
        ans += pq.top().first;
        s = pq.top().second;
        pq.pop();
    }
    cout << ans;
}
