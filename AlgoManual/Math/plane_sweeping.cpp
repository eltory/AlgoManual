//
//  plane_sweeping.cpp
//  AlgoManual
//
//  Created by LSH on 07/07/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

typedef int dtype;

using namespace std;

class rect {
public:
    dtype x, y, height, width;
};

int main() {
    int n; cin >> n;
    
    vector <dtype> x, y;
    vector <rect> d(n);
    
    double ans = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> d[i].x >> d[i].y >> d[i].width >> d[i].height;
        
        x.push_back(d[i].x);
        x.push_back(d[i].x + d[i].width);
        y.push_back(d[i].y);
        y.push_back(d[i].y + d[i].height);
    }
    
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    
    for (int i = 0; i < x.size() - 1; i++)
        for (int j = 0; j < y.size() - 1; j++)
            for (int k = 0; k < n; k++)
                if (x[i] >= d[k].x && x[i + 1] <= d[k].x + d[k].width &&
                    y[j] >= d[k].y && y[j + 1] <= d[k].y + d[k].height) {
                    ans += (x[i + 1] - x[i]) * (y[j + 1] - y[j]);
                    break;
                }
    
    cout << ans;
}
