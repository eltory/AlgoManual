//
//  permutation_2.cpp
//  AlgoManual
//
//  Created by LSH on 15/05/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

/**
 *  순열 nPr - 인덱스 내로 해결 할 수 없는 값들을 처리하는 방법
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n, m;
int arr[10];
unordered_map<int, bool> v;
vector<int> vc;

void dfs(int cnt){
    if(vc.size() == m){
        for(int i=0; i<vc.size(); ++i){
            ; // 순열 처리
        }
        return;
    }else{
        for(int i=0; i<n; ++i){
            if(vc.size() < m){
                if(!v[arr[i]]){
                    vc.push_back(arr[i]);
                    v[arr[i]] = true;
                    dfs(i+1);
                    v[arr[i]] = false;
                    vc.pop_back();
                }
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; ++i)
        cin >> arr[i];
    sort(arr, arr+n);
    dfs(0);
    return 0;
}
