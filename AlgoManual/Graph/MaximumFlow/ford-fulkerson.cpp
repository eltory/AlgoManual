//
//  ford-fulkerson.cpp
//  AlgoManual
//
//  Created by LSH on 01/02/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const int MAX_V = 100;
int V;

// cap[u][v] : u에서 v로 보낼 수 있는 용량
// flow[u][v] : u에서 v로 흘러가는 유량 (반대방향은 음수)
int cap[MAX_V][MAX_V], flow[MAX_V][MAX_V];

// flow[][]를 계산하고 총 유량을 리턴함
int networkFlow(int source, int sink){
    memset(flow, 0, sizeof(flow));
    // flow총량을 0으로 초기화
    int total_flow = 0;
    
    while(true){
        // bfs로 증가경로 찾음
        vector<int> parent(MAX_V, -1);
        queue<int> q;
        parent[source] = source;
        q.push(source);
        
        while(!q.empty() && parent[sink] == -1){
            int u = q.front(); q.pop();
            for(int v=0; v<V; ++v){
                //잔여 용량이 남아 있는 간선을 따라 탐색함
                if(cap[u][v] - flow[u][v] > 0 && parent[v] == -1){
                    q.push(v);
                    parent[v] = u;
                }
            }
        }
        // 증가 경로가 없으면 종료함
        if(parent[sink] == -1) break;
        // 증가 경로를 통해 유량을 얼마나 보낼지 결정함
        int amount = INF;
        for(int p=sink; p!=source; p=parent[p])
            amount = min(cap[parent[p]][p] - flow[parent[p]][p], amount);
        // 증가 경로를 통해 유량을 보냄
        for(int p=sink; p!=source; p=parent[p]){
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }
        total_flow += amount;
    }
    return total_flow;
}

int main(){
    
    return 0;
}

