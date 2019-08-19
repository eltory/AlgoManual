//
//  manacher.cpp
//  AlgoManual
//
//  Created by LSH on 01/05/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

/**
 * O(n)
 */
#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;
const int N = 100001 * 2;

string tmp, str;
int A[N];

void manachers(string S, int n){
    int r = 0, p = 0;
    for(int i=0; i<n; ++i){
        if(i <= r) A[i] = min(A[2*p-1], r-i);
        else A[i] = 0;
        while(i-A[i]-1 >= 0 && i+A[i]+1 < n
              && S[i-A[i]-1] == S[i+A[i]+1]) A[i]++;
        if(r < i+A[i]){
            r = i+A[i];
            p = i;
        }
    }
}
