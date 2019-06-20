//
//  merge_sort.cpp
//  AlgoManual
//
//  Created by LSH on 01/02/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

#include <stdio.h>
void merge(int arr[], int buf[], int start, int middle, int end){
    int i = 0, j = 0, k = 0, t = 0;
    i = start;
    j = middle + 1;
    k = start;
    
    while(i <= middle && j <= end){
        if(arr[i] <= arr[j]) buf[k++] = arr[i++];
        else buf[k++] = arr[j++];
    }
    if(i > middle)
        for(t = j; t <= end; t++, k++)
            buf[k] = arr[t];
    else
        for(t = i; i <= middle; t++, k++)
            buf[k] = arr[t];
    
    for(t = start; t <= end; t++)
        arr[t] = buf[t];
    
    for(t = start; t <= end; t++)
        printf("%d ", arr[t]);
    
}
void mergeSort(int arr[], int buf[], int start, int end){
    int middle = 0;
    if(start < end){
        middle = (start + end) / 2;
        mergeSort(arr, buf, start, middle);
        mergeSort(arr, buf, middle+1, end);
        merge(arr, buf, start, middle, end);
    }
}
int main(){
    int arr[5] = {5,4,3,2,1};
    
    for(int i = 0; i < 5; ++i)
        printf("%d ",arr[i]);
    return 0;
}

