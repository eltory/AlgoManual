//
//  combination.cpp
//  AlgoManual
//
//  Created by LSH on 15/05/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

/**
 *  조합 nCr - 이전 수의 참조를 하면 안된다는 것을 생각, 현재의 인덱스 다음 인덱스를
 *            파라미터로 넘겨 이전 값 참조 못하게 방지
 *      n! / r!(n-r)!
 */
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> vc;

void dfs(int cnt){
    if(vc.size() == m){
        for(int i=0; i<vc.size(); ++i){
            ; // 조합처리
        }
        return;
    }
    for(int i=cnt; i<=n; ++i){
        if(vc.size() < m){
            vc.push_back(i);
            dfs(i+1);
            vc.pop_back();
        }
    }
}

int main(){
    cin >> n >> m;
    dfs(1);
    return 0;
}
