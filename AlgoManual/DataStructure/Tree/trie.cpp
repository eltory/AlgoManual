//
//  trie.cpp
//  AlgoManual
//
//  Created by LSH on 01/02/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

/**
 * 문자열을 이진 검색트리로 만들면 O(MlogN)이라 비효율적임
 * 따라서, 트라이 구조를 이용하여 O(M)으로 시간 단축 (M은 문자열 길이)
 * 
 */
#include <stdio.h>
#include <string.h>

typedef struct Trie {
    bool finish;    //끝나는 지점을 표시해줌
    Trie* next[26];    //26가지 알파벳에 대한 트라이
    // 생성자
    Trie() : finish(false) {
        memset(next, 0, sizeof(next));
    }
    // 소멸자: 연결 다 끊어주기
    ~Trie() {
        for (int i=0; i<26; i++)
            if (next[i])
                delete next[i];
    }
    // 문자열 추가부분
    void insert(const char* key) {
        if (*key=='\0')
            finish = true;    //문자열이 끝나는 지점일 경우 표시
        else {
            int curr = *key-'A';
            if (next[curr]==NULL)
                next[curr] = new Trie();    //탐색이 처음되는 지점일 경우 동적할당
            next[curr]->insert(key + 1);    //다음 문자 삽입
        }
    }
    // 문자열 찾기 쿼리 (다양하게 변조해서 사용)
    Trie* find(const char* key) {
        if (*key=='\0')return this;//문자열이 끝나는 위치를 반환
        int curr = *key - 'A';
        if (next[curr]==NULL)return NULL;//찾는 값이 존재하지 않음
        return next[curr]->find(key + 1); //다음 문자를 탐색
    }
}Trie;

int main(){
    
    return 0;
}

