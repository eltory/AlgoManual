//
//  quick_sort.cpp
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

void quick_sort(int first, int last){
    int pivot;
    int i, j;
    
    if(first<last){
        pivot = first;
        i = first;
        j = last;
        
        while(i<j){
            while(input[i]<=input[pivot] && i<last) i++;
            while(input[j]>input[pivot]) j--;
            if(i<j){
                swap(input[i], input[j]);
            }
        }
        swap(input[pivot], input[j]);
        
        quick_sort(first, j-1);
        quick_sort(j+1, last);
    }
}

int main(){
    
    
    return 0;
}
