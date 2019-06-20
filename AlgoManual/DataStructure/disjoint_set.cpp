//
//  disjoint_set.cpp
//  AlgoManual
//
//  Created by LSH on 22/04/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;
const int MAX = 100;
//int parent[MAX];

// 최적화 코드
// 트리를 이용해 상호 배타적 집합을 구현한다.
struct OptimizedDisjointSet{
    vector<int> parent, rank;
    OptimizedDisjointSet(int n) : parent(n), rank(n,1){
        for(int i=0; i<n; ++i)
            parent[i] = i;
    }
    
    // u가 속한 트리의 루트의 번호를 반환한다.
    int find(int u){
        if(u==parent[u]) return u;
        return parent[u] = find(parent[u]);
    }
    
    // u가 속한 트리와 v가 속한 트리를 합친다.
    void merge(int u, int v){
        u = find(u);
        v = find(v);
        // u와 v가 이미 같은 집합에 속하는 경우를 걸러낸다.
        if(u==v) return;
        if(rank[u] > rank[v]) swap(u, v);
        // 이제 rank[v]가 항상 rank[u] 이상이므로 u를 v의 자식으로 넣는다.
        parent[u] = v;
        if(rank[u]==rank[v]) ++rank[v];
    }
};
