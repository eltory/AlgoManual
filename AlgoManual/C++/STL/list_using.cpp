//
//  list.cpp
//  AlgoManual
//
//  Created by LSH on 07/07/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

#include <stdio.h>
#include <list>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    
    list<int> mylist;
    while(n--) {
        char command[10];
        scanf("%s", command);
        
        // push, get, size, count, clear
        if(command[0] == 'p') {
            int value;
            scanf("%d", &value);
            mylist.push_back(value);
        } else if(command[0] == 'g') {
            int idx;
            scanf("%d", &idx);
            list<int>::iterator it = mylist.begin();
            while(idx--) {
                it++;
            }
            printf("%d\n", *it);
        } else if(command[0] == 's') {
            printf("%d\n", mylist.size());
        } else if(command[1] == 'o') {
            int target, cnt = 0;
            scanf("%d", &target);
            for(list<int>::iterator it = mylist.begin(); it != mylist.end(); it++) {
                if(*it == target) {
                    cnt++;
                }
            }
            printf("%d\n", cnt);
        } else {
            mylist.clear();
        }
    }
    
    return 0;
}
