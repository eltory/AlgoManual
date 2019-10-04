//
//  heap2.cpp
//  AlgoManual
//
//  Created by LSH on 29/09/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

#include <algorithm>
#include <iostream>
using namespace std;
const int MAX = 100;

int heap[MAX];
int size = 0;

bool push(int val){
    if(size == MAX){
        cout << "Heap is Full\n";
        return false;
    }
    heap[++size] = val;
    int c = size;
    int p = c/2;
    while(p>0 && heap[p] < heap[c]){
        swap(heap[p], heap[c]);
        c = p;
        p = c/2;
    }
    return true;
}

bool pop(int* val){
    if(size == 0){
        cout << "Heap is Enpty\n";
        return false;
    }
    *val = heap[1];
    heap[1] = heap[size--];
    int p = 1;
    int c = 2;
    while(c <= size){
        if(c+1 <= size && heap[c] < heap[c+1]) c++;
        if(heap[c] < heap[p]) break;
        swap(heap[p], heap[c]);
        p = c;
        c = 2*p;
    }
    return true;
}

int main(){
    
    return 0;
}
