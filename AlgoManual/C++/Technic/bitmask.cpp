//
//  bitmask.cpp
//  AlgoManual
//
//  Created by LSH on 04/03/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

/**
 * Bit mask
 * AND: &, OR: |, XOR: ^, NOT: ~
 */
#include <stdio.h>
using namespace std;

// 켜진 비트 개수 구하기
int bitCount(int x){
    if(x==0) return x;
    return x%2 + bitCount(x/2);
}

// 최소 1인 비트 구하기
int firstBit(int x){
    return (x & -x); // 보수 표현
}

// 최소 원소 지우기
int delFirstBit(int x){
    return x &= (x-1);
}

int main(){
    int elem, shift_bit;
    
    if(elem & (1<<shift_bit)) // 비트 연산의 값은 bool이 아니라 0 또는 1<<shift_bit 임
        printf("Correct bit mask");
    if(elem & (1<<shift_bit) == 1) // 이럴경우 틀림
        printf("Incorrect");
    
    
    elem |= (1<<shift_bit); // 원소 삽입
    elem & (1<<shift_bit); // 원소 여부
    elem &= ~(1<<shift_bit); // 원소 삭제
    elem ^= (1<<shift_bit); // 원소 토글
    
    // 모든 부분 집합 순회하기 - subset = 0일 때까지, (공집합은 포함 안됨)
    for(int subset = elem; subset; subset = ((subset-1) & elem)){
        // subset은 elem의 부분집합
    }
    return 0;
}
