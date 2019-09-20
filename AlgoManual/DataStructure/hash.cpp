//
//  hash.cpp
//  AlgoManual
//
//  Created by LSH on 17/04/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

/**
 *
 */
#include <iostream>
#include <string>   
using namespace std;
const int MAX_KEY = 64;
const int MAX_DATA = 128;
const int MAX_TABLE = 4096;

typedef struct{
    char key[MAX_KEY+1];
    char data[MAX_DATA+1];
}Hash;
Hash tb[MAX_TABLE];

unsigned long hash_func(const char* str){
    unsigned long hash = 5381;
    int c;
    while((c = *str++)){
        hash = ((hash<<5)+hash+c)%MAX_TABLE;
    }
    return hash%MAX_TABLE;
}

int hash_func2(const char* str){
    int hash = 5381;
    int c;
    
    while(*str != '\0'){
        hash = ((hash<<4) + (int)(*str))%MAX_TABLE;
        str++;
    }
    return hash%MAX_TABLE;
}

bool find(const char *key, char *data){
    unsigned long h = hash_func(key);
    int cnt = MAX_TABLE;
    
    while(tb[h].key[0]!=0 && cnt--){
        if(strcmp(tb[h].key, key)==0){
            strcpy(data, tb[h].data);
            return true;
        }
        h = (h+1)%MAX_TABLE;
    }
    return false;
}

bool add(const char *key, char *data){
    unsigned long h = hash_func(key);
    while(tb[h].key[0]!=0){
        if(strcmp(tb[h].key, key)==0)
            return false;
        h = (h+1)%MAX_TABLE;
    }
    strcpy(tb[h].key, key);
    strcpy(tb[h].data, data);
    return true;
}

int main(){
    int T, N, Q;
    char k[MAX_KEY+1];
    char d[MAX_DATA+1];
    cin >> N;
    for(int i=0; i<N; ++i){
        cin >> k >> d;
        add(k, d);
    }
    for(int i=0; i<Q; ++i){
        char k[MAX_KEY + 1];
        char d[MAX_DATA + 1];
        cin >> k;
        if(find(k, d))
            cout << d;
        else
            cout << "Not fount";
    }
    cin >> Q;
    return 0;
}
