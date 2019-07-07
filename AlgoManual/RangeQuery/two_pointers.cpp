//
//  two_pointers.cpp
//  AlgoManual
//
//  Created by LSH on 01/02/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

#include <iostream>
#include <vector>

#define MAX 5005

using namespace std;

int main() {
    int n, m;
    
    cin >> n;
    
    vector<int> A(n);
    
    for (int i = 0; i < n; i++)
        cin >> A[i];
    
    cin >> m;
    
    vector <int> B(m);
    
    for (int i = 0; i < m; i++)
        cin >> B[i];
    
    int a = 0, b = 0;
    
    vector <int> Sorted;
    
    for (int i = 0; i < n + m; i++) {
        if (b == m || (b != m && a < n && A[a] < B[b]))
            Sorted.push_back(A[a++]);
        else
            Sorted.push_back(B[b++]);
    }
    
    for (int x : Sorted)
        cout << x << " ";
}

