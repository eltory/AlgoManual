//
//  flood_fill.cpp
//  AlgoManual
//
//  Created by LSH on 01/05/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

const int N = 100;
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,1,0,-1};
bool visited[N][N];
int matrix[N][N];

int flood_fill(int i, int j){
    for(int k=0; k<4; ++k){
        int x = dx[k] + i;
        int y = dy[k] + j;
        if(x<0 || x>N-1 || y<0 || y>N-1 || visited[x][y]) continue;
        flood_fill(x, y);
    }
    return 1;
}

int main(){
    int area = 0;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            scanf("%d", &matrix[i][j]);
        }
    }
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            area += flood_fill(i, j);
        }
    }
    printf("%d",area);
    return 0;
}

