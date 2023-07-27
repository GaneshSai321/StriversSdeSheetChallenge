#include <bits/stdc++.h> 

/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */
struct Node{
    Node *links[26];
    bool flag=false;
};




class Trie {


public:

Node* root;

    /** Initialize your data structure here. */

    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* node=root;
        for(int i=0;i<word.length();i++){
            int ch=word[i]-'a';
            if(node->links[ch]!=0) node=node->links[ch];
            else{
                node->links[ch]=new Node();
                node=node->links[ch];
            }
        }
        node->flag=true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {

        Node* node =root;
        for(int i=0;i<word.length();i++){
            int ch_ind=word[i]-'a';
            if(!node->links[ch_ind]) return false;
            node=node->links[ch_ind];
        }
        return node->flag;

    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* node =root;
        for(int i=0;i<prefix.length();i++){
            int ch_ind=prefix[i]-'a';
            if(!node->links[ch_ind]) return false;
            node=node->links[ch_ind];
        }
        return true;
    }
};

int strings_cnt(Node* root){
int cnt=0;
for(int i=0;i<26;i++){
    if(root->links[i]!=0){
        cnt+=strings_cnt(root->links[i]);
    }
}
if(root->flag) cnt++;
return cnt;
}

int distinctSubstring(string &word) {
    Trie* mytrie = new Trie();
    //  Write your code here.
    for(int i=0;i<word.length();i++){
        string s="";
        for(int j=i;j<word.length();j++){
            s+=word[j];
            mytrie->insert(s);
        }
    }
    return strings_cnt(mytrie->root);
}
