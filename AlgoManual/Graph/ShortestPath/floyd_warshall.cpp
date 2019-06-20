//
//  floyd_warshall.cpp
//  AlgoManual
//
//  Created by LSH on 01/02/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

/**
 *  O(V^3)
 */
#include <stdio.h>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const int N = 100;

int dist[N][N];

void floyd_warshall(){
    for(int k=0; k<N; ++k)
        for(int i=0; i<N; ++i)
            for(int j=0; j<N; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            scanf("%d", &dist[i][j]);
            if(dist[i][j] == 0) dist[i][j] = INF;
        }
    }
    floyd_warshall();
    return 0;
}
