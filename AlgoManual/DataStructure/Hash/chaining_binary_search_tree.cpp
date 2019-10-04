//
//  chaining_binary_search_tree.cpp
//  AlgoManual
//
//  Created by LSH on 04/10/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

//
//  binary_search_tree.cpp
//  AlgoManual
//
//  Created by LSH on 17/04/2019.
//  Copyright © 2019 LSH. All rights reserved.
//


#include <iostream>
#include <str_func.cpp>
using namespace std;
const int MAX_DATA_SIZE = 128;

typedef struct Node* nptr;
typedef struct Node{
    char data[MAX_DATA_SIZE];
    nptr left, right;
    
    Node(char* key){
        strcpy(data, key);
        left = right = NULL;
    }
    
    void retrieve(nptr curr){
        if(curr == NULL) return;
        preOrder(curr->left);
        preOrder(curr->right);
        delete curr;
    }
    
    nptr findMin(nptr root){
        nptr curr = root;
        while(curr->left != NULL)
            curr = curr->left;
        return curr;
    }
    
    nptr insertion(nptr curr, char* key){
        if(curr == NULL){
            curr = (nptr)malloc(sizeof(Node));
            strcpy(curr->data, key);
            curr->left = curr->right = NULL;
            return curr;
        } else{
            if(strcmp(curr->data, key) > 0)
                curr->left = insertion(curr->left, key);
            else
                curr->right = insertion(curr->right, key);
        }
        return curr;
    }
    
    nptr deletion(nptr curr, char* key){
        nptr tNode = NULL;
        if(curr == NULL){
            cout << key << " does not exist.\n";
            return NULL;
        }
        if(strcmp(curr->data, key) > 0)
            curr->left = deletion(curr->left, key);
        else if(strcmp(curr->data, key) < 0)
            curr->right = deletion(curr->right, key);
        else{
            if(curr->right != NULL && curr->left != NULL){
                tNode = findMin(curr->right);
                strcpy(curr->data, tNode->data);
                curr->right = deletion(curr->right, tNode->data);
            } else{
                tNode = (curr->left == NULL) ? curr->right : curr->left;
                free(curr);
                return tNode;
            }
        }
        return curr;
    }
    
    nptr search(nptr curr, char* key){
        if(curr == NULL)
            return NULL;
        
        if(strcmp(curr->data, key) == 0) return curr;
        else if(strcmp(curr->data, key) > 0) return search(curr->left, key);
        else return search(curr->right, key);
    }
    
    void preOrder(nptr curr){
        if(curr == NULL) return;
        preOrder(curr->left);
        preOrder(curr->right);
    }
    
    void inOrder(nptr curr){
        if(curr == NULL) return;
        inOrder(curr->left);
        inOrder(curr->right);
    }
    
    void postOrder(nptr curr){
        if(curr == NULL) return;
        postOrder(curr->left);
        postOrder(curr->right);
    }
}Node;



