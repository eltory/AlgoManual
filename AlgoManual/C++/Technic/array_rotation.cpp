//
//  array_rotation.cpp
//  AlgoManual
//
//  Created by LSH on 26/09/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

#include <stdio.h>
const int MAX = 100;
const int N = 50;
int m[MAX][MAX];

void rotation(){
    int tmp[MAX][MAX];
    
    for(int i=0; i<N; ++i)
        for(int j=0; j<N; ++j)
            tmp[j][N-i-1] = m[i][j];
}
