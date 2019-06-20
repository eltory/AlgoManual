//
//  duplicated_permutation.cpp
//  AlgoManual
//
//  Created by LSH on 15/05/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

/**
 *  중복순열 nㅠr
 *         n^r
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;
typedef pair<int, int> P;
int n, m;
P arr[10];

map<P, int> v;
map<vector<int>, int> mp;
vector<int> vc;

void dfs(int cnt){
    if(vc.size() == m && !mp.count(vc)){
        mp[vc]=1;
        return;
    }
    for(int i=0; i<n; ++i){
        if(vc.size() < m){
            if(!v[arr[i]]){
                vc.push_back(arr[i].first);
                v[arr[i]] = true;
                dfs(i+1);
                v[arr[i]] = false;
                vc.pop_back();
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; ++i){
        int val;
        cin >> val;
        
        arr[i] = {val, i};
    }
    sort(arr, arr+n);
    dfs(0);
    
    for(auto it = mp.begin(); it != mp.end(); ++it){
        for(int i=0; i<it->first.size(); ++i){
            ; // 중복순열 처리
        }
    }
}
