//
//  semaphores.cpp
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

int _mutex = 1;

/*
 *   Busy waiting 있는 경우
 */
class ProcessA{
private:
    item next_produced;
    
    void _wait(int S){
        while(S<=0)
            ; // no-op
        S--;
    }
    
    void _signal(int S){
        S++;
    }
    
    void semaphore(){
        do{
            _wait(_mutex);
            
            /* critical section */
            
            _signal(_mutex);
            
            /* remainder section */
            
        }while(1);
    }
};

/*
 *   Busy waiting 없는 경우
 */

// 세마포어 변수 int->struct로 재정의
typedef struct{
    int value;  // 기존 세마포어 변수
    struct ProcessB* L; // 세마포어 큐, wait를 호출해서 blocking 된 프로세스 보관
}semaphore;

semaphore _semaphore;
class ProcessB{
private:
    item next_produced;
    
    void _wait(semaphore S){
        S.value--;
        if(S.value < 0){
            S.L = this;
            // block();
        }
    }
    
    void _signal(semaphore S){
        S.value++;
        if(S.value <= 0){
            S.L = NULL;
            // wakeup(P);
        }
    }
    
    void semaphore(){
        do{
            _wait(_semaphore);
            
            /* critical section */
            
            _signal(_semaphore);
            
            /* remainder section */
            
        }while(1);
    }
};
