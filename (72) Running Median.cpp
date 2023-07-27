#include <queue>
void findMedian(int *arr, int n)
{
    // Write your code here
    priority_queue<int>max_heap;
    priority_queue<int,vector<int>,greater<int>>min_heap;

    for(int i=0;i<n;i++){
        if(max_heap.empty()||max_heap.top()>=arr[i]){
            max_heap.push(arr[i]);
        }
        else min_heap.push(arr[i]);

        if((int)(max_heap.size()-min_heap.size())>1) {
            int ele = max_heap.top();
            max_heap.pop();
            min_heap.push(ele);
        }
        if((int)(min_heap.size()-max_heap.size())>0){
            int ele=min_heap.top();
            min_heap.pop();
            max_heap.push(ele);
        }
        // cout<<arr[i]<<" "<<max_heap.top()<<endl;
        if(max_heap.size()==min_heap.size()) cout<<(max_heap.top()+min_heap.top())/2<<" ";
        else cout<<max_heap.top()<<" ";
    }
}