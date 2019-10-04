//
//  hash_chaining_binary_search_tree.cpp
//  AlgoManual
//
//  Created by LSH on 04/10/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "chaining_binary_search_tree.cpp"
using namespace std;
const int MAX_KEY_SIZE = 64;
const int MAX_TABLE_SIZE = 4096;

typedef struct Bucket* ptr;
typedef struct Bucket{
    char data[MAX_DATA_SIZE];   // Key겸 Data, 추가로 설정 가능
    nptr root;   // Chaining
    
    Bucket(){
        root = NULL;
        memset(data, 0, sizeof(data));
    }
    Bucket(char* key){
        strcpy(data, key);
    }
}Bucket;


ptr hashTable[MAX_TABLE_SIZE];

/* 데이터의 해싱값을 반환 (Key) */
unsigned long hashing(char* key){
    unsigned long hash = 5381;  // 골든넘버 소수
    
    while(*key != '\0'){
        hash = (((hash << 5) + *key) + hash);  // hash * 33
        /*
         *  LCG (Linear Congruential Generator)이랑 비슷한 역할로
         *  Random하게 난수 발생역할을 한다.
         */
        key++;
    }
    return hash % MAX_TABLE_SIZE;
}

/* 해싱된 index를 기준으로
 * 해시테이블에서 값 찾기
 */
void search(char* key){
    unsigned long idx = hashing(key);
    ptr p = hashTable[idx];
    nptr root = p->root;
    root = root->search(root, key);
    
    if(p == NULL || root == NULL){
        cout << "Not founded.\n";
        return;
    }
    cout << root->data;
}

/* 해싱된 index에 데이터 삽입
 * 충돌이 일어나면 체이닝으로 이진탐색트리에 삽입
 */
void insertion(char* key){
    unsigned long idx = hashing(key);
    ptr bucket = new Bucket(key);
    
    if(hashTable[idx] == NULL){
        hashTable[idx] = bucket;
    }else{
        ptr p = hashTable[idx];
        nptr root = p->root;
        p->root = root->insertion(root, key);
    }
    cout << "Insertion " << key << " completed.\n";
}

/* 헤싱된 index로 버킷 삭제
 * 체이닝일 경우 리스트 순회하며 찾아 삭제
 */
void deletion(char* key){
    unsigned long idx = hashing(key);
    ptr p = hashTable[idx];
    nptr root = p->root;
    
    if(p == NULL || root->search(root, key) == NULL){
        cout << "Not founded.\n";
        return;
    }
    p->root = root->deletion(root, key);
    cout << "Deletion " << key << " completed.\n";
}
