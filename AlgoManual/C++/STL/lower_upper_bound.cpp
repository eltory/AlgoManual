//
//  lower_upper_bound.cpp
//  AlgoManual
//
//  Created by LSH on 26/09/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> arr = { 1,3,4,5,6,7,7,7,8,9 };

void Upper(){
    int n = 2; // 해당값이 없는 경우
    upper_bound(arr.begin(), arr.end(), n);
    
}

void Lower(){
    int n = 2; // 해당값이 없는 경우
    lower_bound(arr.begin(), arr.end(), n); // 하한선이기 때문에 idx 0 반환;
    //
}
int main(){
    
    
    return 0;
}
