//
//  bellman_ford.cpp
//  AlgoManual
//
//  Created by LSH on 31/01/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

/**
 * 시간복잡도: for문에 의해서 수행시간 결정
 * 가장 바깥 for문 O(V), 안의 두 for문은 모두 간선 순회 O(E) 수행.
 * 따라서, O(VE)
 */
#include <stdio.h>
#include <vector>
using namespace std;
typedef pair<int, int> P;
const int V = 100;
const int INF = 1e8;

vector<vector<P>> adj;
// 음수 사이클이 있을 경우 텅 빈 배열을 반환
vector<int> bellmanFord(int s){
    // 시작점을 제외한 모든 정점까지의 최단 거리 상한을 INF로 둔다.
    vector<int> upper(V, INF);
    upper[s] = 0;
    bool isCycle = false;
    // V번 순회한다.
    for(int i=0; i<V; ++i){
        isCycle = false;
        for(int u=0; u<V; ++u){
            for(P p : adj[u]){
                int v = p.first;
                int w = p.second;
                // (u, v)간선을 따라 완화를 시도한다.
                if(upper[v] > upper[u]+w){
                    upper[v] = upper[u]+w;
                    isCycle = true;
                }
            }
        }
        // 모든 간선에 대해 완화가 실패했을 경우 V-1번도 돌 필요 없이 곧장 종료한다.
        if(!isCycle) break;
    }
    // V번째 순회에서도 완화가 성공했다면 음수 사이클이 있다.
    if(isCycle) upper.clear();
    return upper;
}
int main(){
    return 0;
}
