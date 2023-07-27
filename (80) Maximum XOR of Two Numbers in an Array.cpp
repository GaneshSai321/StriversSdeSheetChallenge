#include <bits/stdc++.h> 

struct Node{
    Node* links[2];
};

class Trie{
    public:
    Node *root;

    Trie(){
        root = new Node();
    }


    void insert(int num){
        Node *temp = root;
        // int mask=1<<31;
        for(int i=31;i>=0;i--){
            int bit = (num>>i)&1;
            if(temp->links[bit]==0) temp->links[bit] = new Node();
            temp=temp->links[bit];
        }
    }

    int max_xor_with(int x){
        int ans=0;
        Node *temp = root;
        for(int i =31;i>=0;i--){
            int xbit= (x>>i)&1;
            // xbit=xbit^1;
            if(temp->links[1-xbit]){
                ans=ans | (1<<i);
                temp=temp->links[1-xbit];
            }
            else temp=temp->links[xbit];
        }
        // cout<<x<<" "<<ans<<endl;
        return ans;
    }

};



int maximumXor(vector<int> A)
{
    // Write your code here.
    Trie* mytrie = new Trie();
    for(int i=0;i<A.size();i++){
        mytrie->insert(A[i]);
    }  
    int ans=0;
    for(int i=0;i<A.size();i++){
        ans=max(ans,mytrie->max_xor_with(A[i]));
    } 
    return ans;
}