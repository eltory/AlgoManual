//
//  stack_list.cpp
//  AlgoManual
//
//  Created by LSH on 16/09/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

#include <iostream>
#include <cstdlib>
using namespace std;
typedef struct node* nptr;
typedef struct node{
    int data;
    nptr prev;
}node;

nptr head = NULL, top = NULL;

void init(){
    head = (nptr)malloc(sizeof(node));
    top = head;
}

nptr isFull(){
    return (nptr)malloc(sizeof(node));
}

bool isEmpty(){
    return top == head;
}

void push(int val){
    nptr container = isFull();
    if(container != NULL){
        container->data = val;
        container->prev = top;
        top = container;
    }
}

void pop(){
    if(!isEmpty()){
        nptr tmp = top->prev;
        free(top);
        top = tmp;
    }
}

int getTop(){
    if(!isEmpty())
        return top->data;
    return -1;
}

int main(){
//    init();
//    push(1);
//    push(2);
//    push(3);
//    push(4);
//    cout << getTop() << endl;
//    pop();
//    cout << getTop() << endl;
//    pop();
//    cout << getTop() << endl;
//    pop();
//    cout << getTop() << endl;
//    pop();
//    cout << getTop() << endl;
//    pop();
//    cout << getTop();
}

