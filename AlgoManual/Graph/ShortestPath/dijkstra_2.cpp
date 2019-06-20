//
//  dijkstra_2.cpp
//  AlgoManual
//
//  Created by LSH on 31/01/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

/**
 * 정점의 수가 적거나 간선의 수가 매우 많은 경우
 * 큐에 보관하지 않고 매번 반복문을 이용해서 방문하지 않은 정점 중 dist[]가 가장 작은 값을 찾는다.
 * 시간복잡도: O(V^2+E)
 */
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
// first: vertex, second: weight
typedef pair<int, int> P;
// 정점의 개수
const int V = 100;
const int INF = 1e8;
// 그래프의 인접 리스트 (연결된 정점 번호, 간선 가중치쌍)
vector<vector<P>> adj;

vector<int> dijkstra(int s){
    vector<int> dist(V, INF);
    
    // 각 정점을 방문했는지 여부를 저장한다.
    vector<bool> visited(V, false);
    dist[s] = 0; visited[s] = true;
    
    while(true){
        // 아직 방문하지 않은 정점 중 가장 가까운 정점을 찾는다.
        int closest = INF, u = 0;
        for(int i=0; i<V; ++i){
            if(dist[i]<closest && !visited[i]){
                u = i;
                closest = dist[i];
            }
        }
        if(closest == INF) break;
        // 가장 가까운 정점을 방문함
        visited[u] = true;
        for(P p : adj[u]){
            int v = p.first;
            if(visited[v]) continue;
            int d = dist[u] + p.second;
            dist[v] = min(dist[v], d);
        }
    }
    return dist;
}

int main(){
    return 0;
}
