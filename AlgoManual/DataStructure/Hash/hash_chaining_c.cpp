//
//  hash_chaining_c.cpp
//  AlgoManual
//
//  Created by LSH on 04/10/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

#include <iostream>
using namespace std;
const int MAX_KEY_SIZE = 64;
const int MAX_DATA_SIZE = 128;
const int MAX_TABLE_SIZE = 4096;

/* strcpy 문자열 복사 */
char* strcpy(char* dst, const char* src){
    int idx = 0;
    while(src[idx++] != '\0'){
        dst[idx] = src[idx];
    }
    dst[idx] = '\0';
    return dst;
}

/* strcmp 문자열 비교 */
bool strcmp(char* a, char* b){
    int idx = 0;
    while(a[idx] != '\0' || b[idx] != '\0'){
        if(a[idx] != b[idx])
            return false;
        idx++;
    }
    if(a[idx] == '\0' && b[idx] == '\0')
        return true;
    return false;
}

typedef struct Bucket* ptr;
typedef struct Bucket{
    char data[MAX_DATA_SIZE];   // Key겸 Data, 추가로 설정 가능
    ptr next;   // Chaining
    
    Bucket(){
        next = NULL;
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
    
    if(p == NULL){
        cout << "Not founded.\n";
        return;
    }
    while(strcmp(p->data, key) != 0){
        p = p->next;
        if(p == NULL)
            return;
    }
    cout << p->data;
}

/* 해싱된 index에 데이터 삽입
 * 충돌이 일어나면 체이닝으로 리스트 연결
 */
void insertion(char* key){
    unsigned long idx = hashing(key);
    ptr bucket = new Bucket(key);
    
    if(hashTable[idx] == NULL){
        hashTable[idx] = bucket;
    }else{
        ptr p = hashTable[idx];
        while(p->next != NULL)
            p = p->next;
        p->next = bucket;
    }
    cout << "Insertion " << key << " completed.\n";
}

/* 헤싱된 index로 버킷 삭제
 * 체이닝일 경우 리스트 순회하며 찾아 삭제
 */
void deletion(char* key){
    unsigned long idx = hashing(key);
    ptr p = hashTable[idx];
    if(p == NULL){
        cout << "Not founded.\n";
        return;
    }
    ptr prev = p;
    while(strcmp(p->data, key) != 0){
        prev = p;
        p = p->next;
        if(p == NULL)
            return;
    }
    prev->next = p->next;
    free(p);
    cout << "Deletion " << key << " completed.\n";
}
