#include <bits/stdc++.h> 
// Stack class.
class Stack {
    
public:

    vector<int> stk;
    int ptr;
    int n;
    
    Stack(int capacity) {
        // Write your code here.
       this->ptr=-1;
       this->n=capacity;
       this->stk.resize(capacity);
    }

    void push(int num) {
        // Write your code here.
        if(ptr==n-1) return;
        stk[++ptr]=num;
    }

    int pop() {
        // Write your code here.
        if(ptr==-1) return -1;
        return stk[ptr--];
    }
    
    int top() {
        // Write your code here.
        if(ptr==-1) return -1;
        return stk[ptr];
    }
    
    int isEmpty() {
        // Write your code here.
        return ptr==-1;
    }
    
    int isFull() {
        // Write your code here.
        return ptr==n-1;
    }
    
};