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

bool compare(vector<int>a,vector<int>b){
	return a[1]<b[1];
}


vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	//	Write your coode here.
	Trie * mytrie= new Trie();
	int q=queries.size();
	vector<int>ans(q);
	int n=arr.size();

	for(int i=0;i<q;i++){
		queries[i].push_back(i);
	}

	sort(queries.begin(),queries.end(),compare);
	sort(arr.begin(),arr.end());

	int ind=0;

	for(int i=0;i<q;i++){
		int ai=queries[i][1];
		int qi=queries[i][2];
		int xi=queries[i][0];
		while(ind<n&&arr[ind]<=ai) {
			mytrie->insert(arr[ind]);
			ind++;
		}

		if(ind==0) ans[qi]=-1;
		else ans[qi]=mytrie->max_xor_with(xi);
	}
	return ans;

}

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

bool compare(vector<int>a,vector<int>b){
	return a[1]<b[1];
}


vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	//	Write your coode here.
	Trie * mytrie= new Trie();
	int q=queries.size();
	vector<int>ans(q);
	int n=arr.size();

	for(int i=0;i<q;i++){
		queries[i].push_back(i);
	}

	sort(queries.begin(),queries.end(),compare);
	sort(arr.begin(),arr.end());

	int ind=0;

	for(int i=0;i<q;i++){
		int ai=queries[i][1];
		int qi=queries[i][2];
		int xi=queries[i][0];
		while(ind<n&&arr[ind]<=ai) {
			mytrie->insert(arr[ind]);
			ind++;
		}

		if(ind==0) ans[qi]=-1;
		else ans[qi]=mytrie->max_xor_with(xi);
	}
	return ans;

}

