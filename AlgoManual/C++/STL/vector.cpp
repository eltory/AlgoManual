//
//  vector.cpp
//  AlgoManual
//
//  Created by LSH on 24/06/2019.
//  Copyright © 2019 LSH. All rights reserved.
//

/**
 *  Vector
 *  
 */
template <typename T>
class vector {
public:
    int _cap, _size;
    T* vc;
    
private:
    
    // Constructor
    vector(int size = 1){
        _cap = size;
        vc = new T[size];
    }
    
    // Deconstructor
    ~vector(){
        delete[] vc;
    }
    
    // Get vector size
    int size(){
        return _size;
    }
    
    // Is vactor empty
    bool empty(){
        return !_size;
    }
    
    // Vector resize
    void resize(int size){
        _cap = size;
        T* tmp = new T[size];
        for(int i=0; i<size; ++i){
            tmp[i] = vc[i];
        }
        delete [] vc;
        vc = tmp;
    }
    
    // Push back
    void push_back(T val){
        if(_size == _cap){
            _cap *= 2;
            resize(_cap);
        }
        vc[_size++] = val;
    }
    
    // Pop back
    void pop_back(){
        if(empty()){
            return;
        }
        vc[--_size] = 0;
    }
    
    // Vector reverse
    void reverse(){
        for(int i=0; i<_size/2; ++i){
            T tmp = vc[i];
            vc[i] = vc[(_size-1)-i];
            vc[(_size-1)-i] = tmp;
        }
    }
    
    // Operator
    T &operator[] (const int& i) const {
        return vc[i];
    }
    
    void operator= (const vector<T>& tmp){
        _cap = tmp._cap;
        _size = tmp._size;
        delete [] vc;
        vc = new T[_cap];
        
        for(int i=0; i<_size; ++i)
            vc[i] = tmp[i];
    }
};

