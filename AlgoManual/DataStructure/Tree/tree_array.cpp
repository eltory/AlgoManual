//
//  tree_array.cpp
//  AlgoManual
//
//  Created by LSH on 17/04/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

#include <iostream>
using namespace std;
const int MAX_N = 10000;
const int MAX_C = 2;

typedef struct{
    int parent;
    int child[MAX_C];
}TreeNode;

TreeNode tree[MAX_N];
int nodeNum;
int edgeNum;
int root;

/**
 *  트리 초기화
 */
void initTree(){
    for(int i=0; i<=nodeNum; ++i){
        tree[i].parent = -1;
        for(int j=0; j<MAX_C; ++j){
            tree[i].child[j] = -1;
        }
    }
}

/**
 *  해당 부모 노드에 child 노드 추가
 */
void addChild(int parent, int child){
    for(int i=0; i<MAX_C; ++i){
        if(tree[parent].child[i] == -1){
            tree[parent].child[i] = child;
            tree[child].parent = parent;
            break;
        }
    }
}

/**
 *  트리의 root 노드 index 반환
 *  없을 경우 -1
 */
int getRoot(){
    for(int i=1; i<=nodeNum; ++i){
        if(tree[i].parent == -1){
            return i;
        }
    } return -1;
}

/**
 *  전위 root - left - right
 */
void preOrder(int root){
    int child;
//    cout << root;
    for(int i=0; i<MAX_C; ++i){
        child = tree[root].child[i];
        if(child != -1){
            preOrder(child);
        }
    }
}

/**
 *  중위 left - root - right
 */
void inOrder(int root){
    int child;
    child = tree[root].child[0];
    if(child != -1){
        inOrder(child);
    }
//    cout << root;
    child = tree[root].child[1];
    if(child != -1){
        inOrder(child);
    }
}

/**
 *  후위 left - right - root
 */
void postOrder(int root){
    int child;
    for(int i=0; i<MAX_C; ++i){
        child = tree[root].child[i];
        if(child != -1){
            preOrder(child);
        }
    }
//    cout << root;
}

