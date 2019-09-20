//
//  binary_search_tree_reculsive.cpp
//  AlgoManual
//
//  Created by LSH on 20/09/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct Node* nptr;
typedef struct Node{
    int data;
    nptr left, right;
}Node;

nptr root = NULL;

nptr findMin(nptr root){
    nptr curr = root;
    while(curr->left != NULL)
        curr = curr->left;
    return curr;
}

nptr insertion(nptr curr, int key){
    if(curr == NULL){
        curr = (nptr)malloc(sizeof(Node));
        curr->data = key;
        curr->left = curr->right = NULL;
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

void preOrder(nptr curr){
    if(curr == NULL) return;
    cout << curr->data << endl;
    preOrder(curr->left);
    preOrder(curr->right);
}

int main(){
    root = insertion(root, 5);
    root = insertion(root, 3);
    root = insertion(root, 7);
    root = insertion(root, 1);
    root = insertion(root, 9);
    root = insertion(root, 6);
    
    root = deletion(root, 7);
    
    preOrder(root);
    return 0;
}
