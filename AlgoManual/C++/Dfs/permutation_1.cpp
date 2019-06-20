//
//  permutation_1.cpp
//  AlgoManual
//
//  Created by LSH on 15/05/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

/**
 *  순열 nPr
 *      n! / (n-r)!
 */
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n, m;
vector<int> vc; // 내가 출력할 것
bool v[10]; // 그 숫자가 쓰는지확인

void dfs(){
    if (vc.size() == m){
        for(int i=0; i<vc.size(); ++i){
            ; // 순열에 대한 작업
        }
        return;
    }
    
    for (int i = 1; i <= n; i++){
        if (!v[i]){
            v[i] = true;
            vc.push_back(i);
            dfs();
            vc.pop_back();
            v[i] = false;
        }
    }
}

int main(){
    cin >> n >> m;
    dfs();
    return 0;
}
