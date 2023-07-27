#include<bits/stdc++.h>

class LRUCache
{
public:
list<pair<int,int>>dq;
unordered_map<int, list<pair<int,int>>::iterator> ma;

int cap;

    LRUCache(int capacity)
    {
        // declare the size
        cap=capacity;
    }

    int get(int key)
    {
        int val =-1;
        // not present in cache
        if(ma.find(key)==ma.end()){
            return -1;
        }

        // present in cache
        auto pr=*(ma[key]);
        val=pr.second;

        //update reference 
        dq.erase(ma[key]);
        dq.push_front({key,val});
        ma[key]=dq.begin();
        return val;
    }

    void put(int key, int value)
    {

        //overwriting case
        if(ma.find(key)!=ma.end()){
            auto it= ma[key];
            dq.erase(it);
        }
        
        else if(dq.size()==cap){
            // delete least recently used element
            auto last = dq.back();
 
            // Pops the last element
            dq.pop_back();
 
            // Erase the last
            ma.erase(last.first);
            
        }

        dq.push_front({key,value});
        ma[key]=dq.begin();

    }
};
