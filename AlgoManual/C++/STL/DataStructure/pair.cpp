//
//  pair.cpp
//  AlgoManual
//
//  Created by LSH on 26/09/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

/**
 *  Pair
 *
 */
template <typename T1, typename T2>
class pair {
public:
    T1 first;
    T2 second;
    
    bool operator <(const pair<T1, T2> &a) {
        if (first == a.first)
            return second < a.second;
        return first < a.first;
    }
};

