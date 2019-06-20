//
//  dijkstra_1.cpp
//  AlgoManual
//
//  Created by LSH on 31/01/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

/**
 * 시간복잡도: 1. 각 정점마다 인접한 간선들을 모두 검사하는 작업, 2. 우선순위 큐에 원소를 넣고 삭제하는 작업
 * 각 정점은 정확히 한 번씩 방문되고, 따라서 모든 간선은 한 번씩 검사된다 --> O(E)
 * 최대 큐에 들어갈 정점의 수는 E까지므로 O(E), 또 힙을 정렬하는데 O(lgE)가 걸림
 * 따라서, 총 O(E)xO(lgE) = O(ElgE)
 * E < V^2이므로 O(ElgV)
 */
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> P;
// 정점의 개수
const int V = 100;
const int INF = 1e8;
// 그래프의 인접 리스트 (연결된 정점 번호, 간선 가중치쌍)
vector<vector<P>> adj;
vector<int> dist(V, INF);
// 최단 경로 추적을 위한 방문체크 (단, 양방향으로 그래프 그려야함)
vector<vector<bool>> visit;

vector<int> dijkstra(int s){
    dist[s] = 0;
    // first: vertex, second: weight
    priority_queue<P> pq;
    pq.push(P(0, s));
    while(!pq.empty()){
        int w = -pq.top().first;
        int u = pq.top().second;
        pq.pop();
        // 만약 지금 꺼낸 것보다 더 짧은 경로를 알고 있다면 지금 꺼낸 것을 무시한다.
        if(dist[u] < w) continue;
        for(P p : adj[u]){
            int v = p.first;
            int d = w+p.second;
            // 더 짧은 경로를 발견하면, dist[]를 갱신하고 우선순위 큐에 넣는다.
            if(dist[v] > d){
                dist[v] = d;
                pq.push(P(-d, v));
            }
        }
    }
    return dist;
}

// 최단경로 추적을 위한 bfs
void bfs(int s, int d){
    queue<int> q;
    q.push(d);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(u == s) continue;
        for(P p : adj[u]){
            int prev = p.first;
            int w = p.second;
            if(dist[u] == dist[prev]+w){
                visit[prev][u] = true;
                q.push(prev);
            }
        }
    }
}
int main(){
    return 0;
}
