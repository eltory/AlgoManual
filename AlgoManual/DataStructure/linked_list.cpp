//
//  linked_list.cpp
//  AlgoManual
//
//  Created by LSH on 19/08/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

#include <iostream>
using namespace std;
const int MAX_NODE = 100;

typedef struct Node* Nptr;  // Node Pointer : Nptr로 명명
typedef struct Node{        // Node 정의 : 데이터, prev 포인터, next 포인터
    int data;
    Nptr prev;
    Nptr next;
}Node;

typedef struct NodeHeap* NHptr; // Node Heap Pointer : NHptr로 명명
typedef struct NodeHeap{        // NodeHeap 정의 : 사용여부, Node 객체 포인터
    bool use;
    Node node;
}NodeHeap;

NodeHeap heap[MAX_NODE];    // Node Heap은 환형 더블리 링크드 리스트로 구현

/**
 *  링크드 리스트 힙의 각 노드의 사용여부를 false로 초기화
 *  삭제효과는 사용여부를 false로 설정
 */
void initHeap(){
    for(int i=0; i<MAX_NODE; ++i){
        heap[i].use = false;
    }
}

/**
 *  각 노드의 데이터를 초기화함
 *  좌, 우의 포인터는 모두 자신을 가리킴
 */
void initNode(Nptr node){
    node->data = 0;
    node->prev = node;
    node->next = node;
}

/**
 *  새로 사용할 노드를 초기화 시켜서 리턴함
 *  만약 힙 메모리가 모두 사용되었을 경우 NULL을 반환
 */
Nptr getNode(){
    for(int i=0; i<MAX_NODE; ++i){
        if(!heap[i].use){
            heap[i].use = true;
            initNode(&heap[i].node);
            return &heap[i].node;
        }
    }
    return NULL;
}

/**
 *  노드 삭제는 실제 노드 자체를 삭제시키는 것이 아닌
 *  사용여부를 false로 바꾸면서 가상의 삭제를 시킴(Heap 메모리 유지)
 */
void destroyNode(Nptr node){
    NHptr hnode = (NHptr)((int*)node - 1);
    hnode->use = false;
}

/**
 *  노드를 이어 붙이는 작업으로 현재 리스트의 말단 주소와 추가할 데이터를 받음
 *  다음으로 사용할 노드를 반환 받음
 *  그 노드에 데이터를 추가함
 *  만약 현재 리스트가 비어 있다면 현재 최초로 생긴 노드를 반환
 *  그게 아니라면,
 */
Nptr appendNode(Nptr head, int data){
    Nptr node = getNode();
    node->data = data;
    if(head == NULL){
        return node;
    }else{
        Nptr last = head->prev;
        last->next = node;
        head->prev = node;
        node->prev = last;
        node->next = head;
        return head;
    }
}

/**
 *  노드를 삭제하려면 현재의 링크드 리스트와 삭제할 노드의 주소값을 받음
 *  리스트의 다음이 자신을 가리킨다면 --> 리스트는 하나의 노드로 구성
 *      그 하나의 노드 삭제 후 NULL(리스트가 비어잇음)을 반환
 *  아니라면 --> 리스트는 여러개의 노드로 구성
 *      prev - node - next  -->  prev - next 식으로 포인터 변경 후
 *      node를 파괴함(실제 파괴 x, 사용여부로 가상의 파괴 o)
 *  만약 list의 head를 삭제 시킨다면 새로운 head로 head->next 노드를 반환
*   아니라면 현재의 head 반환
 */
Nptr removeNode(Nptr head, Nptr node){
    if(head == head->next){
        destroyNode(node);
        return NULL;
    }else{
        Nptr prev = node->prev;
        Nptr next = node->next;
        prev->next = next;
        prev->prev = prev;
        destroyNode(node);
        return (head == node) ? next : head;
    }
}

int main(){
    int data;
    Nptr head = NULL;   // list 포인터는 결국 링크드 리스트의 head(말뚝용) 노드를 가리킨다.
    Nptr node;          // node 포인터는 임시 포인터
    initHeap();         // 링크드 리스트 heap 초기화
    
    cin >> data;
    head = appendNode(head, data);
    node = head;
}
