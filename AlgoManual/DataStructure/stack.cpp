//
//  stack.cpp
//  AlgoManual
//
//  Created by LSH on 17/04/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

/**
 * Container : deque
 * LIFO : Last In First Out
 * push : O(1)
 * pop  : O(1)
 */
#include <iostream>
using namespace std;
const int MAX_N = 100;

int top;
int stack[MAX_N];

void init(void){
    top = 0;
}

bool isEmpty(void){
    return top==0;
}

bool isFull(void){
    return top==MAX_N;
}

bool push(int value){
    if(isFull()){
        cout << "stack overflow";
        return false;
    }
    stack[top++] = value;
    return true;
}

bool pop(int *value){
    if(isEmpty()){
        cout << "stack is empty";
        return false;
    }
    top--;
    *value = stack[top];
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
