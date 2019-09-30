//
//  critical_section.cpp
//  AlgoManual
//
//  Created by LSH on 30/09/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

#include <iostream>
using namespace std;

const int BUFF_ZISE = 10;
typedef struct item{
    int data;
}item;
item buffer[BUFF_ZISE];

bool flag[2];   /* flag[i] 가 true면 pi는 임계영역을 실행할 수 있음 */
int turn = 0;   /* turn이 i 이면, pi가 임계영역을 실행할 수 있음 */
int i, j;

/*
 *  임계영역 문제해결을 위한 요구사항
 *
 *  1. Mutual exclusion : 어떤 프로세스가 임계영역의 코드를 실행하고 있으면,
 *                        다른 프로세스는 그것을 실행할 수 없다.
 *  2. Progress : 임계영역의 코드를 실행하는 프로세스가 없고 그것을 실행하려는 프로세스 pi가
 *                있으면, 다른 프로세스는 remainder section을 실행하지 않은 상태일 때만 pi의
 *                임계영역 실행 여부에 관여할 수 있다. 그리고 이러한 선택은 무한정 연기될 수 없다.
 *  3. Bounded waiting : 어떤 프로세스가 임계영역의 실행을 요청하여 그것이 허가되기 전에 다른 프로세스가
 *                       임계영역을 실행하는 것이 허용되는 시간의 범위가 정해져야 한다.
 */

class Process{
private:
    item next_produced;
    
    void pro(){
        do{
            /* entry section */
            
                /* critical section */
            
            /* exit section */
            
                /* remainder section */
            
        }while(1);
    }
};

/* Two - Process */
class ProcessA{
private:
    item next_produced;
    
    /*
     *  1 : Y
     *  2 : N - turn == 0이고 p1이 임계영역을 실행할 준비가 되어 있으면, p0가 rs을 실행하고 있다고해도
     *          p1은 이를 실행할 수 없다.
     *  3 : N
     */
    void algorithm_1(){
        do{
            while(turn != i)
                ;
    
            /* critical section */
            
            turn = j;
            
            /* remainder section */
            
        }while(1);
    }
    
    /*
     *  1 : Y
     *  2 : N - p0와 p1이 동시에 임계영역을 실행하려고 한다고 가정, flag[0]와 flag[1]이 모두 true인
     *          상황이 발생할 수 있다. 그러면 p0와 p1은 모두 루프에서 빠져나오지 못함.
     *          따라서 progress를 만족하지 못한다.
     *  3 : N
     */
    void algorithm_2(){
        do{
            flag[i] = true;
            while(flag[j] == true)
                ;
            
            /* critical section */
            
            flag[i] = false;
            
            /* remainder section */
            
        }while(1);
    }
    
    /*
     *  1 : Y
     *  2 : Y
     *  3 : Y
     */
    void algorithm_3(){
        do{
            flag[i] = true;
            turn = j;
            while(flag[j] == true && turn == j)
                ;
            
            /* critical section */
            
            flag[i] = false;
            
            /* remainder section */
            
        }while(1);
    }
};

const int N = 100;
bool choosing[N];
int number[N];

/* Multi - Process */
class ProcessB{
private:
    item next_produced;
    
    void bakery_algorithm(){
        do{
            choosing[i] = true;
            int max_num = 0;
            for(int j=1; j<N; ++j)
                max_num = max(number[j], number[j-1]);
            number[i] = max_num + 1;
            choosing[i] = false;
            for(int j=0; j<N; ++j){
                while(choosing[j]);
                while((number[j] != 0) && ((number[j], j) < (number[i], i)));
                /* 번호표를 받고있는 스레드가 있는지 확인 */
            }
            
            /* critical section */
            
            number[i] = 0;
            
            /* remainder section */
            
        }while(1);
    }
};
