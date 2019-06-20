//
//  topological_sort.cpp
//  AlgoManual
//
//  Created by LSH on 01/05/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
const int N = 100;
vector<vector<int>> graph;
stack<int> S;
priority_queue<int> PQ;
bool visited[N];
int inDegree[N];
int n, m, x, y;

// dfs를 이용한 위상정렬
void using_dfs(int u){
    visited[u] = true;
    for(int v : graph[u]){
        if(visited[v]) continue;
        using_dfs(v);
    }
    S.push(u);
}

int main(){
    scanf("%d %d", &n, &m);
    graph.resize(n);
    for(int i=0; i<m; ++i){
        scanf("%d %d", &x, &y);
        graph[x].push_back(y);
        inDegree[y]++;
    }
    
    // dfs를 이용한 위상정렬
    for(int i=0; i<n; ++i){
        if(!visited[i]) using_dfs(i);
    }
    while(S.size()){
        printf("%d ", S.top());
        S.pop();
    }
    
    // pq를 이용한 위상정렬
    for(int i=0; i<n; ++i){
        if(!inDegree[i]) PQ.push(-i);
    }
    while(PQ.size()){
        int u = -PQ.top();
        PQ.pop();
        printf("%d ", u);
        for(int v : graph[u]){
            if(!--inDegree[v]) PQ.push(-v);
        }
    }
    return 0;
}


