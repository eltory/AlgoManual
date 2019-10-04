//
//  linked_list(single).cpp
//  AlgoManual
//
//  Created by LSH on 17/04/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

/**
 *  단일 연결리스트,  정렬된 순서 유지
 */

#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct node* nptr;
typedef struct node{
    int data;
    nptr next;
}node;

nptr head;

nptr createNode(int val){
    nptr nNode = (nptr)malloc(sizeof(node));
    nNode->data = val;
    nNode->next = NULL;
    return nNode;
}

void init(){
    if(head == NULL){
        head = createNode(-1);
        return;
    }
    nptr p = head->next;
    while(p != NULL){
        nptr tmp = p->next;
        free(p);
        p = tmp;
    }
    head->next = NULL;
}

void insertion(int val){
    nptr p = head;
    nptr n = p->next;
    
    while(n != NULL && val > n->data){
        p = n;
        n = n->next;
    }
    nptr newNode = createNode(val);
    p->next = newNode;
    newNode->next = n;
}

void deletion(int val){
    nptr p = head;
    nptr n = p->next;
    while(n != NULL){
        if(n->data == val) {
            p->next = n->next;
            free(n);
            return;
        }
        p = n;
        n = n->next;
    }
}

void print(){
    nptr p = head->next;
    while(p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << "\n";
}
