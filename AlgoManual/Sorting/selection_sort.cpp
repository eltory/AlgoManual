//
//  selection_sort.cpp
//  AlgoManual
//
//  Created by LSH on 01/02/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

/**
 *
 */
#include <iostream>
using namespace std;
const int MAX_NUM = 100;
int input[MAX_NUM];
int num;

void selection_sort(void){
    for(int i=0; i<num; ++i){
        int minIdx = i;
        for(int j=i+1; j<num; ++j)
            if(input[minIdx]>input[j])
                minIdx = j;
        swap(input[i], input[minIdx]);
    }
}

int main(){
    
    return 0;
}

