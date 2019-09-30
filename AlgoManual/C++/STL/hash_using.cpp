//
//  hash.cpp
//  AlgoManual
//
//  Created by LSH on 07/07/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_set<string> hash;
    
    for(int i = 0; i < n; i++) {
        int command;
        string key;
        cin >> command >> key;
        
        if(command == 1) {
            hash.insert(key);
        } else if(command == 2) {
            hash.erase(key);
        } else {
            if(hash.count(key) == 1) {
                printf("1\n");
            } else {
                printf("0\n");
            }
        }
    }
    
    return 0;
}
