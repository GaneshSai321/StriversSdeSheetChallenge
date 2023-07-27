#include <bits/stdc++.h> 

struct Node{
    Node* links[26];
    int pre_cnt=0;
    int word_cnt=0;
};

class Trie{
    private: Node* root;

    public:

    Trie(){
        // Write your code here.
        root=new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node* node=root;
        for(int i=0;i<word.length();i++){
            int ch=word[i]-'a';
            node->pre_cnt+=1;
            if(node->links[ch]!=0) node=node->links[ch];
            else{
                node->links[ch]=new Node();
                node=node->links[ch];
            }
        }
        node->pre_cnt+=1;
        node->word_cnt+=1;
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node* node =root;
        for(int i=0;i<word.length();i++){
            int ch_ind=word[i]-'a';
            if(!node->links[ch_ind]) return 0;
            node=node->links[ch_ind];
        }
        return node->word_cnt;
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        int cnt=0;
        Node* node =root;
        for(int i=0;i<word.length();i++){
            int ch_ind=word[i]-'a';
            if(!node->links[ch_ind]) return 0;
            node=node->links[ch_ind];
        }
        return node->pre_cnt;

    }

    void erase(string &word){
        // Write your code here.
        Node* node =root;
        for(int i=0;i<word.length();i++){
            int ch_ind=word[i]-'a';
            node->pre_cnt-=1;
            if(!node->links[ch_ind]) return ;
            node=node->links[ch_ind];
        }
        if(node->word_cnt>0){
            node->word_cnt-=1;
            node->pre_cnt-=1;
        } 
    }
};
