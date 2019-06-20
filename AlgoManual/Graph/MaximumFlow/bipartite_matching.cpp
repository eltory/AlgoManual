//
//  bipartite_matching.cpp
//  AlgoManual
//
//  Created by LSH on 01/02/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;
const int N = 100;

int n, m;
bool visited[N];
int b[N];
vector<vector<int>> graph;

bool dfs(int u){
    if(visited[u]) return 0; // 방문 된 정점은 매칭 불가
    visited[u] = true;
    for(int next : graph[u]){
        int v = next;
        if(!b[v] || dfs(b[v])){ // 매칭이 되어있지 않은 정점을 만나거나 이미 매칭된 정점이 다른 정점과 매칭이 가능할 때
            b[v] = u; // 매칭 시켜준 뒤 1을 리턴
            return true;
        }
    }
    return false; // 매칭 실피
}

int bi_match(){
    int rtn = 0;
    for(int i=0; i<n; ++i){ // 모든 정점에 대하여 매칭을 시도
        memset(visited, false, sizeof(visited));
        if(dfs(i)) rtn++;
    }
    return rtn;
}

int main(){
    scanf("%d %d", &n, &m);
    graph.resize(n);
    for(int i=0; i<n; ++i){
        int v, x;
        scanf("%d", &v);
        while(v--){
            scanf("%d", &x);
            graph[i].push_back(x);
        }
    }
    printf("%d", bi_match());
    return 0;
}

