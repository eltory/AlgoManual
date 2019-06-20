//
//  topological_sort.cpp
//  AlgoManual
//
//  Created by LSH on 01/02/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

/**
 * 위상정렬이 가능하려면 DAG 그래프여야 한다.
 * 방향성이 있고, 사이클이 없는 그래프
 * 핵심은 indegree의 차수가 0인 것부터 하나씩 큐에 넣으면서 다음 노드들도 indegree 수정해가며 큐에 넣음
 * 방문 순서가 곧, 위상정렬 순서임
 */
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
vector<int> indegree;
vector<int> seq;
vector<vector<int>> adj;
int N, M;

void topology(){
    priority_queue<int> pq;

    // 초기 pq 설정, in = 0 인 노드부터
    for(int i=0; i<N; ++i)
        if(!indegree[i])
            pq.push(-i);
    
    // 큐에 넣으면서 방문
    while(pq.size()){
        int u = -pq.top();
        pq.pop();
        seq.push_back(u);
        for(int v : adj[u])
            if(--indegree[v]) pq.push(-v);
    }
}

int main(){
    // indegree 올리기
    return 0;
}
