#include <bits/stdc++.h> 
class Queue {
public:

    vector<int> q;
    int frt;
    Queue() {
        // Implement the Constructor
        frt=-1;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return frt==-1||frt==q.size();
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        q.push_back(data);
        if(frt==-1) frt=0;
    }

    int dequeue() {
        // Implement the dequeue() function
        if(!isEmpty())
            return q[frt++];
        return -1;
    }

    int front() {
        // Implement the front() function
        if(!isEmpty()) return q[frt];
        return -1;
    }

    //  17. 23. 11. 
};