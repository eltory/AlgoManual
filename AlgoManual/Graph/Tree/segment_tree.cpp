//
//  segment_tree.cpp
//  AlgoManual
//
//  Created by LSH on 01/02/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

/**
 *  구간트리
 *  parent(n) - left_child(2n+1) - right_child(2n) : parent = 0
 *  parent(n) - left_child(2n) - right_child(2n+1) : parent = 1
 *  Full binary tree 에 가까움으로 포인터 연결보다는 배열이 효율적
 *  n 일 경우 편하게 4n으로 잡음 배열
 *  LIS - dp(N^2), segment(NlogN)
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef long long int lld;

class segment_tree{
public:
    vector<lld> node;
    
    segment_tree(int n){
        node.resize(1<<((int)ceil(log2(n))+1));
    }
    ~segment_tree(){
        node.clear();
    }
    
    /* Init segment tree */
    lld init(vector<lld>& input, int n, int start, int end){
        if(start == end){
            return node[n] = input[start];
        }else{
            return node[n] = init(input, 2*n, start, (start+end)/2) + init(input, 2*n+1, (start+end)/2+1, end);
        }
    }
    
    /* Update segment tree */
    void update(int n, int start, int end, int idx, lld diff){
        if(idx<start || idx>end) return;
        node[n] += diff;
        if(start != end){
            update(2*n, start, (start+end)/2, idx, diff);
            update(2*n+1, (start+end)/2+1, end, idx, diff);
        }
    }
    
    /* Query (in this moment for sumarization) */
    lld sum(int n, int start, int end, int left, int right){
        if(left>end || right<start) return 0;
        else if(left<=start && end<=right) return node[n];
        return sum(2*n, start, (start+end)/2, left, right) + sum(2*n+1, (start+end)/2+1, end, left, right);
    }
    
    /* Query (in this moment for minimum value) */
    lld mmin(int n, int start, int end, int left, int right){
        if(left>end || right<start) return 1e7;
        else if(left<=start && end<=right) return node[n];
        return min(mmin(2*n, start, (start+end)/2, left, right), mmin(2*n+1, (start+end)/2+1, end, left, right));
    }
};

int main(){
    vector<lld> a = {1,4,-3,7,6,-2,0,1};
    segment_tree st = segment_tree(a.size());
    st.init(a, 1, 0, a.size()-1);
    st.update(1, 0, a.size()-1, 2, 4);
    cout << st.mmin(1, 0, a.size()-1, 5, 7)<<endl;
    return 0;
}
