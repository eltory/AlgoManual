//
//  simulated_annealing.cpp
//  AlgoManual
//
//  Created by LSH on 26/06/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

/**
 *  while (시간이 될때까지) {
 *      현재 상태에서 어느 정도 변화를 시킨 상태를 만들어내고 다음 상태라고 이름을 붙인다.
 *      다음 상태를 평가한다;
 *      if (다음 상태 평가치 >= 현재 상태 평가치) 현재 상태 = 다음 상태;
 *  }
 *  담금질 기법, P = e^((E1-E2)/kT)
 *  P: 확률(새로운 상태로 바꼈을 때 이득을 볼 확률)
 *  e: 자연상수
 *  E1: 기존상태의 에너지
 *  E2: 새로운샹태의 에너지
 *  k: 볼츠만 상수 (1.312412)
 *  T: 온도 (1)
 */
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 1000;
int circle[MAX];
int idxV[MAX];

int main(){
    double CT = 1;              // 초기온도
    double K = 1.312412;        // 블츠만 상수
    int n = 100;
    for(int i = 0; i < 1000; i++){
        
        // 바꿀 두개를 랜덤으로 정함
        int fIdx = rand() % n;
        int sIdx = rand() % n;
        if(fIdx == sIdx){
            sIdx++;
            sIdx %= n;
        }

        // 두개를 바꿔보고
        swap(circle[fIdx], circle[sIdx]);
        swap(idxV[fIdx], idxV[sIdx]);

        // 테스트
        vector<double> tmpAns = Check(circle);
        double tmpLength = (tmpAns[n-1] + circle[n-1]) + circle[0];

        // 다시 원상복구하고
        swap(circle[fIdx], circle[sIdx]);
        swap(idxV[fIdx], idxV[sIdx]);

        // 담금질
        double p = exp((length-tmpLength)/(K*CT));
        if(length >= tmpLength || p > double(rand())/RAND_MAX){
            // 새결과를 반영
            swap(circle[fIdx], circle[sIdx]);
            swap(idxV[fIdx], idxV[sIdx]);
            length = tmpLength;
            ansV = tmpAns;
        }

        CT *= 0.9999;
    }

    return 0;
}
