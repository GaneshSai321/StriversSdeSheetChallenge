#include <bits/stdc++.h> 

void insertsorted(stack<int>&stack,int num){
	if(stack.empty()|| stack.top()<=num) {
		stack.push(num);
		return;
	}
	int ele = stack.top();stack.pop();
	insertsorted(stack,num);
	stack.push(ele);
}

void sortStack(stack<int> &stack)
{
	// Write your code here
	if(stack.empty()) return ;

	int num = stack.top();
	stack.pop();

	sortStack(stack);
	insertsorted(stack,num);

}