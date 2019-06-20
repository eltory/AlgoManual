//
//  coord_comp.cpp
//  AlgoManual
//
//  Created by LSH on 01/05/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

/**
 * 좌표 압축기법
 * N(<=10억)개의 점이 1차원 직선상에 존재한다 가정
 * M(<=10억)개의 쿼리를 처리해야함 (x~y 구간에 있는 점의 수를 출력하는 쿼리)
 * 좌표의 등장 수는 많아봐야 N+2*M개를 이용
 * 따라서 우리는 최대 N+2*M개의 좌표를 인덱싱하여 정렬 된 순서대로 1~N+2*M의 번호를 매겨준 뒤 BIT 등을 이용하여 처리
 */
#include <stdio.h>
#include <vector>
using namespace std;
typedef pair<int, int> P;
vector<int> idx;
vector<int> a;
vector<P> qry;
int get_idx(int x){
    return (int)(lower_bound(idx.begin(), idx.end(), x) - idx.begin());
}
int main(){
    int n, m;
    for(int i=0; i<n; ++i){
        scanf("%d", &a[i]);
        idx.push_back(a[i]);
    }
    for(int i=0; i<m; ++i){
        scanf("%d %d", &qry[i].first, &qry[i].second);
        idx.push_back(qry[i].first);
        idx.push_back(qry[i].second);
    }
    sort(idx.begin(), idx.end());
    idx.erase(unique(idx.begin(), idx.end()), idx.end());
    return 0;
}
