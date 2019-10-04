//
//  red_black_tree.cpp
//  AlgoManual
//
//  Created by LSH on 20/09/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

#include <iostream>
#include <cstdlib>
using namespace std;
typedef enum Color{
    RED,
    BLACK
}Color;

typedef struct RedBlackNode* nptr;
typedef struct RedBlackNode{
    int data;
    Color color;
    nptr left, right;
    
    RedBlackNode(){
        color = RED;
        left = right = NULL;
    }
    
    ~RedBlackNode(){
        left = right = NULL;
    }
}Node;

nptr root = NULL;
nptr NIL = NULL;


/*  LL
 *  Right Rotation을 통해 왼쪽으로 치우친 트리를 오른쪽으로 균형맞춤
 */
nptr LL(nptr parent){
    nptr tmp;
    tmp = parent->left;
    parent->left = tmp->right;
    tmp->right = parent;
    return tmp;
}

/*  RR
 *  Left Rotation을 통해 오른쪽으로 치우친 트리를 왼쪽으로 균형맞춤
 */
nptr RR(nptr parent){
    nptr tmp;
    tmp = parent->right;
    parent->right = tmp->left;
    tmp->left = parent;
    
    return tmp;
}

nptr findMin(nptr root){
    nptr curr = root;
    while(curr->left != NULL)
        curr = curr->left;
    return curr;
}

void restructing(){
   
}

void recoloring(){
    
}
nptr insertion(nptr curr, int key){
    if(curr == NULL){
        NIL = new Node();
        NIL->color = BLACK;
        curr = new Node();
        curr->color = BLACK;
        curr->left = curr->right = NIL;
        return curr;
    } else{
        if(curr->data > key)
            curr->left = insertion(curr->left, key);
        else
            curr->right = insertion(curr->right, key);
    }
    return curr;
}

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
    return curr;
}

nptr search(nptr curr, int key){
    if(root == NULL)
        return NULL;
    
    if(curr->data == key) return curr;
    else if(curr->data > key) return search(curr->left, key);
    else return search(curr->right, key);
}

int main(){
    root = insertion(root, 5);
    root = insertion(root, 3);
    root = insertion(root, 7);
    root = insertion(root, 1);
    root = insertion(root, 9);
    root = insertion(root, 6);
    
    root = deletion(root, 7);
    
    return 0;
}
