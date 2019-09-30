//
//  semaphore_linux.cpp
//  AlgoManual
//
//  Created by LSH on 30/09/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define WORD_COUNT_PER_LINE 8
#define DELAY_COUNT 10000000
#define NAME_LEN 1024
#define TASK_NUM 3
pthread_mutex_t Mutext;

void hufsPrinter(int arg){
    
    int taskId = arg;
    int i, j;
    printf("%d\n", taskId);
    
    while(1){
        /* wait */
        pthread_mutex_lock(&Mutext);
        
        /* Critical Section */
        for(i=0; i<WORD_COUNT_PER_LINE; ++i){
            for(j=0; j<DELAY_COUNT; ++j){   // working delay
                printf("%d ", taskId);
                fflush(0);
            }
        }
        printf("\n\n");
        
        /* signal */
        pthread_mutex_unlock(&Mutext);
    }
    return;
}

int main(void){
    
    int i, j;
    int args = 0;
    char tackName[NAME_LEN];
    pthread_t thread_t[TASK_NUM];
    
    // create mutex
    for(i=0; i<TASK_NUM; ++i){
        sprintf(tackName, "Printer%d", i);
        printf("Creating %s.\n", tackName);
        fflush(stdout);
        pthread_mutex_init(&Mutext, NULL);  // mutext initialize
        if(pthread_create(&thread_t[i], NULL, hufsPrinter, (void*)((int)i)) < 0){
            printf("pthread_create error!\n");
            return 1;
        }
    }
    
    printf("Before starting the scheduler.\n");
    fflush(stdout);
    for(i=0; i<TASK_NUM; ++i){
        pthread_join(thread_t[i], NULL);
    }
    return 0;
}
