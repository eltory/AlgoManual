//
//  parametric_search.cpp
//  AlgoManual
//
//  Created by LSH on 01/02/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

/**
 *  최대, 최소를 찾는 최적화 문제 --> 바이너리의 개념으로 범위에 속하는게 있는지 없는지의 결정 문제로 변환
 *  1) 결정 문제를 정의했을 때, 쉽게 풀 수 있는 경우
 *  2) (최솟값을 구하는 경우) 최솟값이 x라면, x이상의 값에 대해서는 모두 조건을 만족
 *  3) (최댓값을 구하는 경우) 최댓값이 x라면, x이하의 값에 대해서는 모두 조건을 만족
 */
#include <stdio.h>
