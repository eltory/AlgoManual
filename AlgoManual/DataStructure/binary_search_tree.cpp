//
//  binary_search_tree.cpp
//  AlgoManual
//
//  Created by LSH on 17/04/2019.
//  Copyright © 2019 LSH. All rights reserved.
//


#include <iostream>
#include <cstdlib>
using namespace std;
typedef struct TreeNode* nptr;
typedef struct TreeNode{
    int data;
    nptr left, right;
}TreeNode;

nptr root = NULL;

/**
 *  트리노드 생성
 */
nptr create(int key){
    nptr node = (nptr)malloc(sizeof(TreeNode));
    node->left = NULL;
    node->right = NULL;
    node->data = key;
    return node;
}

/**
 *  key 검색
 */
nptr search(int key, bool func){
    nptr parent = root;
    nptr prev = parent;
    while(parent != NULL){
        if(parent->data == key){
            if(func) return prev;
            return parent;
        }else if(parent->data < key){
            if(parent->right == NULL){
                return parent;
            }
            prev = parent;
            parent = parent->right;
        }else {
            if(parent->left == NULL){
                return parent;
            }
            prev = parent;
            parent = parent->left;
        }
    }
    return parent;
}

/**
 *  트리노드 삽입
 *  Insert func = 0
 */
void insertion(int key){
    nptr findLoc = search(key, 0);
    if(findLoc == NULL){
        root = create(key);
    }else{
        nptr node = create(key);
        if(findLoc->data < key) findLoc->right = node;
        else if(findLoc->data > key) findLoc->left = node;
    }
}

/**
 *  트리노드 삭제
 *  Delete func = 1
 */
void deletion(int key){
    nptr findLoc = search(key, 1);
    if(findLoc != NULL){
        if(findLoc == root){
            if(findLoc->left == NULL && findLoc->right == NULL){
                free(root);
            }else if((findLoc->left == NULL) || (findLoc->right == NULL)){
                free(root);
                if(findLoc->left != NULL) root = findLoc->left;
                else if(findLoc->right != NULL) root = findLoc->right;
            }else{
                
            }
        }else{
            if(findLoc->left == NULL && findLoc->right == NULL){        // 자식노드가 없는 경우
                
            }else if((findLoc->left == NULL) || (findLoc->right == NULL)){        // 하나의 서브트리만 있는 경우
                
            }else{        // 두개의 서브트리가 있는 경우
                
            }
        }
    }
}

void preOrd(nptr parent){
    if(parent == NULL) return;
    cout << parent->data << "\n";
    preOrd(parent->left);
    preOrd(parent->right);
}

void inOrd(nptr parent){
    if(parent == NULL) return;
    preOrd(parent->left);
    cout << parent->data << "\n";
    preOrd(parent->right);
}

void postOrd(nptr parent){
    if(parent == NULL) return;
    preOrd(parent->left);
    preOrd(parent->right);
    cout << parent->data << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    return 0;
}
