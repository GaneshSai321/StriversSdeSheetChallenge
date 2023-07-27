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
        // cout<<word<<" inserted\n";
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


void solve(Node * root, string &ans, string s){
    // cout<<s<<" "<<ans<<endl;
    // if(root->flag) cout<<" ya a word ends here\n";
    if(root->flag&&s.length()>ans.length()) ans=s;
     for(int i=0;i<26;i++){
         if(root->links[i]!=0&&root->flag){
            //  cout<<char(i+'a')<<endl;
             string temp= s+char(i+'a');
             solve(root->links[i],ans,temp);
         }
        //  else return;
     }
}

string completeString(int n, vector<string> &a){
    // Write your code here.
    Trie * mytrie= new Trie();
    for(auto word: a){
        mytrie->insert(word);
    }
 string ans ="";
 Node * root = mytrie->root;
 for(int i=0;i<26;i++){
   if (root->links[i] != 0) {
       char ch= char(i+'a');
       string str="";
       str+=ch;
     solve(root->links[i], ans,str);
   }
 }
 if(ans=="") return "None";
 return ans;

}