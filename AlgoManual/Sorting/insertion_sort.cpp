//
//  insertion_sort.cpp
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

void insertion_sort(void){
    for(int i=1; i<num; ++i){
        int j = i-1;
        while((0<=j) && (input[i]<input[j])){
            swap(input[j], input[j+1]);
            j--;
        }
    }
}

int main(){
    
    return 0;
}
