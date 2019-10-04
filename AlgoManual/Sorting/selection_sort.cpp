//
//  selection_sort.cpp
//  AlgoManual
//
//  Created by LSH on 01/02/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

/**
 *  [ 현재 index에 들어가야할 값을 index이후의 값들 중'선택'해서 넣는 알고리즘 - Selection ]
 *
 *  선택 정렬은 매 차례마다 정렬되지 않은 원소들을 모두 확인하여 각 인덱스에 맞는 원소를 선택하여
 *  해당 인덱스의 원소와 교환해주는 정렬.
 *  매 차례마다 남은 원소들을 모두 확인하기 때문에
 *
 *  [ Time ] beset = avg = worst = O(N^2)
 *
 */
#include <iostream>
using namespace std;
const int MAX_NUM = 100;
int input[MAX_NUM];
int num;

void selection_sort(void){
    for(int i=0; i<num; ++i){
        int minIdx = i;
        for(int j=i+1; j<num; ++j)
            if(input[minIdx]>input[j])
                minIdx = j;
        swap(input[i], input[minIdx]);
    }
}

int main(){
    
    return 0;
}

