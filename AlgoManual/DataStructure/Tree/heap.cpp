//
//  heap.cpp
//  AlgoManual
//
//  Created by LSH on 17/04/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

/**
 * Container : vector
 * Complete Binary Search Tree
 * push : O(logN) -- 삽입된 원소의 위치를 조정 비교 연산횟수
 * pop  : O(logN) -- 삭제된 원소와 마지막 원소를 바꾸고 위치를 조정 비교 연산횟수
 */

#include <iostream>
using namespace std;
const int MAX_SIZE = 100;

int size = 0;
int heap[MAX_SIZE];

void init(void){
    size = 0;
}

bool isEmpty(void){
    return size <= 0;
}

bool isFull(void){
    return size+1 > MAX_SIZE;
}

bool push(int value){
    if(isFull()){
        cout << "heap is full";
        return false;
    }
    int curr = size;
    heap[size++] = value;
    while(curr>0 && heap[curr]>=heap[(curr-1)/2]){
        int tmp = heap[(curr-1)/2];
        heap[(curr-1)/2] = heap[curr];
        heap[curr] = tmp;
        curr = (curr-1)/2;
    }
    return true;
}

bool pop(int *value){
    if(isEmpty()){
        cout << "fail";
        return false;
    }
    *value = heap[0];
    size--;
    heap[0] = heap[size];
    int curr = 0;
    while(curr*2+1 < size){
        int child;
        if(curr*2+2 == size)
            child = curr*2+1;
        else
            child = heap[curr*2+1]<heap[curr*2+2] ? curr*2+1:curr*2+2;
        if(heap[curr]>=heap[child])
            break;
        int tmp = heap[curr];
        heap[curr] = heap[child];
        heap[child] = tmp;
        curr = child;
    }
    return true;
}

int main(){
    while(isEmpty()){
        int value;
        if(pop(&value)){
            cout << value;
        }
    }
    return 0;
}
