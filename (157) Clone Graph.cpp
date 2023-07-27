#include <bits/stdc++.h> 
/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/

graphNode *cloneGraph(graphNode *node)
{
    // Write your code here.
	map<int,bool>mp;
	map<int,graphNode*>addr;
	queue<graphNode*>q;
	graphNode* root = new graphNode(node->data);
	mp[node->data] =true;
	q.push(node);
	addr[node->data] = root;
	while(!q.empty()){
		graphNode* temp = q.front();
		q.pop();
		graphNode* newTemp;

		//create new node if not exist.
		if(addr.find(temp->data)==addr.end()){
			newTemp = new graphNode(temp->data);
			addr[temp->data] = newTemp;
		}
		else newTemp = addr[temp->data];

		for(auto x : temp->neighbours){
			graphNode* frnd;
			if(addr.find(x->data)==addr.end()){
			frnd = new graphNode(x->data);
			addr[x->data] = frnd;
			}
			else frnd = addr[x->data];
			newTemp->neighbours.push_back(frnd);			

			if(mp.find(x->data)==mp.end()) {
				mp[x->data] =true;
				q.push(x);
			}
		}
	}
	return root;
}