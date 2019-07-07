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
int d[MAX], n;

// 원하는 값이 있는지 없는지 반환(logN)
bool bsearch(int val){
    int l = 0, r  = n - 1;
    
    while(l <= r){
        int mid = (l+r)/2;
        if(val == d[mid]) return true;
        else if(val > d[mid]) l = mid + 1;
        else r = mid - 1;
    }
    
    return false;
}

int main() {
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
        cin >> d[i];
    sort(d, d+n);
    int query;
    cin >> query;
    while (query--) {
        int x; cin >> x;
        
        if (bsearch(x)) cout << "exist" << endl;
        else cout << "not exist" << endl;
    }
}
