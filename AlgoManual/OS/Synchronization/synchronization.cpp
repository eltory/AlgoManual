//
//  synchronization.cpp
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

int in = 0;
int out = 0;
int counter = 0;

class Produer_Process{
private:
    item next_produced;
    
    void pro(){
        while(1){
            /* produce an item in next_produced */
            
            while(counter == BUFF_ZISE)
                ;   /* do nothing */
            buffer[in] = next_produced;
            in = (in+1) % BUFF_ZISE;
            counter++;
            /*
                register1 = counter
                regisert1 = regisert1 + 1
                counter = register1
             */
        }
    }
};

class Consumer_Process{
private:
    item next_consumed;
    
    void con(){
        while(1){
            while(counter == 0)
                ;   /* do nothing */
            next_consumed = buffer[out];
            out = (out+1) % BUFF_ZISE;
            counter--;
            /*
             register2 = counter
             regisert2 = regisert2 - 1
             counter = register2
             */
            
            /* consume the item in next_consumed */
        }
    }
};

/**
 *  pro p와 con p가 동시에 counter++, counter-- 실행시 다음 3가지 상태 중 하나가됨
 *  Race condition 발생 --> Synchronization 필요
 */

/*
    1️⃣
    register1 = counter
    regisert1 = register1 + 1
    counter = register1
    register2 = counter
    register2 = register2 - 1
    counter = register2
 
    result: counter = 0
 */

/*
    2️⃣
    register1 = counter
    register1 = register1 + 1
    register2 = counter
    register2 = register2 - 1
    counter = register1
    counter = register2
 
    result: counter = -1
 */

/*
    3️⃣
    register1 = counter
    register1 = register1 + 1
    register2 = counter
    register2 = register2 - 1
    counter = register2
    counter = register1
 
    result: counter = 1
 */
