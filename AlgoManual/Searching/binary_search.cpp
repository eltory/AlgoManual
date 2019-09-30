//
//  binary_search.cpp
//  AlgoManual
//
//  Created by LSH on 01/02/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 5005;
int d[MAX], N, query;

// 원하는 값이 있는지 없는지 반환(logN) 위치도 반환
bool bsearch(int val, int* key){
    int l = 0, r = N-1;
    
    while(l <= r){
        int mid = (l+r)/2;
        if(val == d[mid]) {
            *key = mid;
            return true;
        }
        else if(val > d[mid]) l = mid+1;
        else r = mid-1;
    }
    
    return false;
}

int main() {
    cin >> N;
    for (int i=0; i<N; ++i) cin >> d[i];
    
    sort(d, d+N);
    cin >> query;
    while (query--) {
        int x, idx = -1;
        cin >> x;
        if (bsearch(x, &idx)) {
            cout << "exist at " << idx << endl;
        } else cout << "not exist" << endl;
    }
}
