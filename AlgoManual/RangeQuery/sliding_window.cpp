//
//  sliding_window.cpp
//  AlgoManual
//
//  Created by LSH on 01/02/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

typedef int val_d;

int main() {
    
    int n, k;
    
    cin >> n >> k;
    
    vector <val_d> d(n);
    
    for (int i = 0; i < n; i++)
        cin >> d[i];
    
    val_d sum = 0, max = 0;
    
    for (int i = 0; i < n; i++) {
        if (i < k) sum += d[i];
        else sum = sum - d[i - k] + d[i];
        max = (max < sum) ? sum : max;
    }
    
    cout << max;
}

