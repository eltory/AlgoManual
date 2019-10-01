//
//  avl_tree.cpp
//  AlgoManual
//
//  Created by LSH on 20/09/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct AVLNode* nptr;
typedef struct AVLNode{
    int data;
    nptr left, right;
}Node;

nptr root;

/* AVL노드의 높이 재귀로 반환 */
int height(nptr node){
    int h = 0;
    if(node != NULL){
        int left = height(node->left);
        int right = height(node->right);
        h = max(left, right) + 1;
    }
    return h;
}

/* 자식노드들의 높이 차이 왼쪽-오른쪽 */
int diff(nptr node){
    int left = height(node->left);
    int right = height(node->right);
    int d = left - right;
    return d;
}

/* RR rotation */
nptr RR(nptr parent){
    nptr tmp;
    tmp = parent->right;
    parent->right = tmp->left;
    tmp->left = parent;
    return tmp;
}

/* LL rotation */
nptr LL(nptr parent){
    nptr tmp;
    tmp = parent->left;
    parent->left = tmp->right;
    tmp->right = parent;
    return tmp;
}

/* LR rotation */
nptr LR(nptr parent){
    // LR 회전은 왼쪽 자식을 기준으로 RR, 본인을 기준으로 LL회전합니다.
    nptr tmp;
    tmp = parent->left;
    parent->left = RR(tmp);
    return LL(parent);
}

/* RL rotation */
nptr RL(nptr parent){
    nptr tmp;
    tmp = parent->right;
    parent->right = LL(tmp);
    return RR(parent);
}

/* AVL트리의 높이차를 유지시키는 balance 함수 */
nptr balance(nptr curr){
    int dif = diff(curr);

    if(dif > 1){    // 왼쪽 서브트리에 추가되어 발란스 깨짐
        if(diff(curr->left) > 0) curr = LL(curr);   // 왼쪽 자식에 추가됨
        else curr = LR(curr);   // 오른쪽 자식에 추가됨
    }else if(dif < -1) {    // 오른쪽 서브트리에 추가되어 발란스 깨짐
        if(diff(curr->right) > 0) curr = RL(curr);  // 오른쪽 자식에 추가됨
        else curr = RR(curr);   // 왼쪽 자식에 추가됨
    }
    return curr;
}

/* Right Least 구하기 */
nptr findMin(nptr root){
    nptr curr = root;
    while(curr->left != NULL)
        curr = curr->left;
    return curr;
}

/* 삽입 후 발란스 조정 */
nptr insertion(nptr curr, int key){
    if(curr == NULL){
        curr = (nptr)malloc(sizeof(Node));
        curr->data = key;
        curr->left = curr->right = NULL;
        return curr;
    } else{
        if(curr->data > key) curr->left = insertion(curr->left, key);
        else curr->right = insertion(curr->right, key);
        
        curr = balance(curr);
    }
    return curr;
}

/* 삭제 후 발란스 조정 */
nptr deletion(nptr curr, int key){
    nptr tNode = NULL;
    if(curr == NULL)
        return NULL;
    
    if(curr->data > key)
        curr->left = deletion(curr->left, key);
    else if(curr->data < key)
        curr->right = deletion(curr->right, key);
    else{
        if(curr->right != NULL && curr->left != NULL){
            tNode = findMin(curr->right);
            curr->data = tNode->data;
            curr->right = deletion(curr->right, tNode->data);
        } else{
            tNode = (curr->left == NULL) ? curr->right : curr->left;
            free(curr);
            return tNode;
        }
    }
    curr = balance(curr);
    return curr;
}
