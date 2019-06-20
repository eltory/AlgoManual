//
//  queue.cpp
//  AlgoManual
//
//  Created by LSH on 17/04/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

/**
 * Container : deque
 * FIFO : First In First Out
 * push : O(1)
 * pop  : O(1)
 */
#include <iostream>
using namespace std;
const int MAX_N = 100;

int front, rear;
int queue[MAX_N];

void init(void){
    front = 0;
    rear = 0;
}

bool isEmpty(void){
    return front==rear;
}

bool isFull(void){
    if((rear+1)%MAX_N == front)
        return true;
    return false;
}

bool push(int value){
    if(isFull()){
        cout << "queue is full";
        return false;
    }
    queue[rear++] = value;
    if(rear==MAX_N)
        rear = 0;
    return true;
}

bool pop(int *value){
    if(isEmpty()){
        cout << "queue is empty";
        return false;
    }
    *value=queue[front++];
    if(front==MAX_N)
        front = 0;
    return true;
}

int main(){
    while(!isEmpty()){
        int value;
        if(pop(&value)){
            cout << value << endl;
        }
    }
    return 0;
}
