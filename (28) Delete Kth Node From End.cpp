/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* removeKthNode(Node* head, int k)
{
    // Write your code here.
    
    Node* fast=head,*slow=head,*slowPrev=0;
    for(int i=0;i<k-1;i++){
        fast=fast->next;
    }
    //edge case when k value is N...
    if(fast->next==0) return head->next;

    while(fast->next!=0){
        fast=fast->next;
        slowPrev=slow;
        slow=slow->next;
    }
    slowPrev->next=slowPrev->next->next;
    return head;
}
