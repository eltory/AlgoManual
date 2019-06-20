//
//  kmp.cpp
//  AlgoManual
//
//  Created by LSH on 01/02/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

/**
 * 문자열을 brute force로 찾을 경우 O(MN)
 * 시간복잡도: O(N+M)
 * 매 한글자씩 비교하는게 아니라, 내가 찾고자 하는 문자열을 대응했을때 같은 부분 문자열만큼 건너뛴 후 검색
 * 실패함수를 만들어 위치 공유 - pi[x] <- 접두사 == 접미사인 최대 길이
 */
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
string a, b;
vector<int> pi;

void getpi(){
    pi.resize(b.length());
    int j = 0;
    for (int i=1; i<b.length(); i++){
        while (j>0 && b[i]!=b[j])
            j = pi[j-1];        //불일치가 일어날 경우
        if (b[i]==b[j])
            pi[i] = ++j;        //prefix가 같은 가중치만큼 pi를 정해줍니다.
    }
}

void kmp(){
    int j = 0;
    for (int i=0; i<a.length(); i++){
        while (j>0 && a[i]!=b[j])        //현재 j만큼 찾았는데 이번에 비교하는 문자가 다른 경우
            j = pi[j-1];        //문자열 B를 failure function 이후 부터 비교를 해줍니다.
        if (a[i]==b[j]){            //비교하는 문자가 같은 경우
            if (j==b.length()-1){    //문자열 B를 전부 탐색하였기 때문에 답에 위치를 넣어줍니다.
                //res.push_back(i - b.length() + 1);
                j = pi[j];    //다음 탐색을 위하여 이번에도 failure function 이후 부터 비교를 해줍니다.
            }
            else
                j++;    //문자열 B의 다음 단어를 비교해줍니다.
        }
    }
}

int main(){
    return 0;
}
