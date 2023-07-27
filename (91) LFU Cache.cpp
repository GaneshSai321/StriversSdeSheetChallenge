#include <bits/stdc++.h> 
class LFUCache
{
public:
    // current least frequency
    int minfreq=0;
    int cap=0;
    int cursize=0;
    // for frequency and corresponding lists
    map<int,list<pair<pair<int,int>,int>>>fmap;   //key,val,freq
    map<int,list<pair<pair<int,int>,int>>::iterator>kmap;
    LFUCache(int capacity)
    {
        // Write your code here.
        cap=capacity;
    }

    int get(int key)
    {
        // Write your code here.
        if(kmap.find(key)!=kmap.end()){
            //delete the node in the corresponding frequency map and update in lru.
            auto it=kmap[key];
            auto par= *(it);
            int val=par.first.second;
            int freq=par.second;
            //erase in keymap
            kmap.erase(key);
            //erase in list of fmap and if minfreq==freq and it gets emptied update minfreq
            fmap[freq].erase(it);
            if(fmap[freq].size()==0&&freq==minfreq) minfreq++;
            //reinsert in freq+1 list
            fmap[freq+1].push_front({{key,val},freq+1});
            //update in kmap
            kmap[key]=fmap[freq+1].begin();
            return val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        // Write your code here.
        
            //if key already exist
            if(kmap.find(key)!=kmap.end()){
                kmap.erase(key);
            }
            else if(cap==cursize){
                //remove the lru in lfu and also in kmap.
                auto par = fmap[minfreq].back();
                fmap[minfreq].pop_back();
                kmap.erase(par.first.first);
            }
            minfreq=1;
            cursize++;
            fmap[1].push_front({{key,value},1});
            kmap[key]=fmap[1].begin();
        
    }
};
