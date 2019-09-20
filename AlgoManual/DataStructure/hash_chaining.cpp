//
//  hash_chaining.cpp
//  AlgoManual
//
//  Created by LSH on 17/09/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX_TABLE = 5;    // 테이블 크기
const int MAX_KEY = 8;      // include null
const int MAX_DATA = 12;    // 해시테이블에 넣을 데이터의 수
const int DELETE_COUNT = 6; // 삭제할 데이터의 수
const int FIND_COUNT = 8;   // 찾을 데이터의 수

typedef struct node* nptr;
typedef struct node{
    char key[MAX_KEY];
    int val;
    nptr next;
}node;

nptr tb[MAX_TABLE]; // 해시 테이블(해당 인덱스에 리스트로 작성)
char keys[MAX_DATA][MAX_KEY];   // 문자열 key들
int values[MAX_DATA];   // key에 대응하는 값들

void init(){
    
    // 해시테이블 초기화
    for(int i=0; i<MAX_TABLE; ++i){
        nptr cur = tb[i];
        nptr tmp;
        while(cur != NULL){
            tmp = cur;
            cur = cur->next;
            free(tmp);
        }
        tb[i] = NULL;
    }
    
    // 랜덤함수를 위한 srand와 seed
    srand(time(NULL));
    
    // key에 대응하는 값들 초기화
    for(int i=0; i<MAX_DATA; ++i){
        values[i] = rand()%100+1;
    }
    
    // 문자열 key들 초기화
    for(int i=0; i<MAX_DATA; ++i){
        for(int j=0; j<MAX_KEY-1; ++j){
            
        }
    }
}


