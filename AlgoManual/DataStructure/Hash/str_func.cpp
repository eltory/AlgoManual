//
//  str_func.cpp
//  AlgoManual
//
//  Created by LSH on 04/10/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

/* strcpy 문자열 복사 */
char* strcpy(char* dst, const char* src){
    int idx = 0;
    while(src[idx++] != '\0'){
        dst[idx] = src[idx];
    }
    dst[idx] = '\0';
    return dst;
}

/* strcmp 문자열 비교 */
int strcmp(char* a, char* b){
    int idx = 0;
    while(a[idx] != '\0' || b[idx] != '\0'){
        if(a[idx] != b[idx])
            return a[idx]-b[idx];
        idx++;
    }
    return 0;
}
