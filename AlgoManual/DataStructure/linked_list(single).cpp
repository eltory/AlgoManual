//
//  linked_list(single).cpp
//  AlgoManual
//
//  Created by LSH on 17/04/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

#include <iostream>
using namespace std;
const int MAX_NODE = 100;
typedef struct node{
    int data;
    struct node* prev;
    struct node* next;
}Node;

typedef struct{
    bool use;
    Node node;
}NodeHeap;
NodeHeap heap[MAX_NODE];

void init(void){
    for(int i=0; i<MAX_NODE; ++i)
        heap[i].use = 0;
}

void initNode(Node* node){
    node->data=0;
    node->prev=node;
    node->next=node;
}

Node* getNode(void){
    for(int i=0; i<MAX_NODE; ++i){
        if(!heap[i].use){
            heap[i].use = true;
            initNode(&heap[i].node);
            return &heap[i].node;
        }
    }
    return NULL;
}

void delNode(Node* node){
    NodeHeap* heap_node = (NodeHeap*)((int*)node-1);
    heap_node->use = false;
}

Node* appendNode(Node* list, int data){
    Node* node = getNode();
    node->data = data;
    if(list==NULL)
        return node;
    else{
        Node* last = list->prev;
        last->next = node;
        list->prev = node;
        node->prev = last;
        node->next = list;
        return list;
    }
}
