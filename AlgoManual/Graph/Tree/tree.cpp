//
//  tree.cpp
//  AlgoManual
//
//  Created by LSH on 01/05/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    string label;  // 저장할 자료형
    TreeNode* parent;  // 부모 노드를 가리키는 포인터
    vector<TreeNode*> children;  // 자손 노드들을 가리키는 포인터의 배열
};

// 주어진 트리의 각 노드에 저장된 값을 모두 출력한다.
void printLabels(TreeNode* root){
    // 루트에 저장된 값을 출력한다.
    cout << root->label << endl;
    // 각 자손들을 루트로 하는 서브트리에 포함된 값들을 재귀적으로 호출한다.
    for(int i=0; i<root->children.size(); ++i){
        printLabels(root->children[i]);
    }
}

// root를 루트로 하는 트리의 높이를 계산하기
int height(TreeNode* root){
    int h = 0;
    for(int i=0; i<root->children.size(); ++i){
        h = max(h, 1+height(root->children[i]));
    }
    return h;
}
