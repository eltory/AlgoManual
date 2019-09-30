//
//  lis.cpp
//  AlgoManual
//
//  Created by LSH on 01/02/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> P;
const int MAX = 100;
P track[MAX];
int num[MAX];
int dp[MAX];
int N;


int lower_bound_custom(int end, int n){
    int start = 0;
    while(start < end){
        int mid = (start+end)/2;
        if(dp[mid] >= n) end = mid;
        else start = mid+1;
    }
    return end;
}

int upper_bound_custom(int end, int n){
    int start = 0;
    while(start < end){
        int mid = (start+end)/2;
        if(dp[mid] > n) end = mid;
        else start = mid+1;
    }
    return end;
}

// O(N^2)
void lis1(){
    
}

/* O(NlogN) with Binary Search
 * Track을 두고 증가 수열도 구하기
 */
void lis2(){
    int idx = 0;
    dp[0] = num[0];
    track[0] = P(0, num[0]);
    for(int i=1; i<N; ++i){
        if(dp[idx] < num[i]){
            dp[++idx] = num[i];
            track[i] = P(idx, num[i]);
        }else{
            //auto at = lower_bound(dp, dp+idx, num[i]);
            //*at = num[i];
            
            int at = lower_bound_custom(idx, num[i]);
            dp[at] = num[i];
            
            track[i] = P(at, num[i]);
        }
    }
    reverse(track, track+N);
}

// O(NlogN) with Segment Tree
void lis3(){
    
}

int main(){
    
    
    return 0;
}
