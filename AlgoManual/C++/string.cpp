//
//  string.cpp
//  AlgoManual
//
//  Created by LSH on 17/04/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

/**
 * 함수에 파라미터로 넘길경우 vector, string 등 &를 붙이는게 더 빠름
 * 값을 복사하는게 아니라 주소값으로 참조하게 만듬
 */
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int N = 12345;
    string S = "77777";
    
    // String to int
    N = stoi(S, NULL, 10);
    
    // Int to string
    S = to_string(N);
    
    // Reverse string (현재의 값을 반전시킴, 리턴 값 없음)
    reverse(S.begin(), S.end());
    
    // 소수점 출력
    cout << fixed ;// << double ;
    cout.precision(6); // 6째 자리까지
    
    return 0;
}
