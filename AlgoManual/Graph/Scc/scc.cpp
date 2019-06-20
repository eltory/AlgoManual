//
//  scc.cpp
//  AlgoManual
//
//  Created by LSH on 01/05/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
const int MAX = 10000;

int V, E, cnt;
int dfsn[MAX], sNum, sn[MAX]; // sNum : SCC 개수 , sn[i] i가 속한 SCC의 번호
vector<int> adj[MAX];
bool finished[MAX]; // SCC 분리가 끝난 정점만 true
stack<int> S;
vector<vector<int>>SCC;

// 자신의 결과값을 리턴하는 DFS 함수
int DFS(int here){
    dfsn[here] = ++cnt;  // dfsn 결정
    S.push(here); // 스택에 자신 push
    
    // 자신의 dfsn, 자식들의 결과나 dfsn 중 가장작은 번호를 result에 저장
    int result = dfsn[here];
    for(int next : adj[here]){
        // 아직 방문하지 않은 이웃
        if(dfsn[next] == 0)
            result = min(result, DFS(next));
        // 방문은 했으나 아직 SCC로 추출되지는 않은 이웃
        else if(!finished[next])
            result = min(result, dfsn[next]);
    }
    
    // 자신, 자신의 자손들이 도달 가능한 제일 높은 정점이 자신일 경우 SCC 추출
    if(result == dfsn[here]){
        vector<int> hereSCC;
        // 스택에서 자신이 나올 때까지 pop
        while(1){
            int t = S.top();
            S.pop();
            hereSCC.push_back(t);
            sn[t] = sNum;
            if(t == here)
                break;
        }
        // 출력을 위해 원소 정렬
        sort(hereSCC.begin(), hereSCC.end());
        // SCC 추출
        SCC.push_back(hereSCC);
        sNum++;
    }
    return result;
}

int main(){
    // 그래프 정보 입력
    scanf("%d %d", &V, &E);
    for(int i = 0; i < E; ++i){
        int A, B;
        scanf("%d %d", &A, &B);
        adj[A-1].push_back(B-1);
    }
    
    // DFS를 하며 SCC추출
    for(int i = 0; i < V; ++i)
        if(dfsn[i] == 0)
            DFS(i);
    // 출력을 위해 SCC들을 정렬
    sort(SCC.begin(), SCC.end());
    
    // SCC 개수
    printf("%d\n",sNum);
    // 각 SCC 출력
    for(auto& hereSCC : SCC){
        for(int here : hereSCC)
            printf("%d ",here+1);
        puts("-1");
    }
}

