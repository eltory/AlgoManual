//
//  bubble_sort.cpp
//  AlgoManual
//
//  Created by LSH on 01/02/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
using namespace std;
const int N = 10;
void bubble(int []);

int main(){
    int arr[N] = {5,4,3,2,1,-1,-2,-3,-4,-5};
    bubble(arr);
    for(int i = 0; i < N; ++i)
        printf("%d ", arr[i]);
    return 0;
}

void bubble(int arr[]){
    for(int i=0; i<N-1; ++i){
        for(int j=0; j<N-1-i; ++j){
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }
}
