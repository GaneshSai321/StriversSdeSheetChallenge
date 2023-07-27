#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    LinkedListNode<int>*fast=head,*slow=head;
    while(fast&&fast->next){
        fast=fast->next->next;
        slow=slow->next;
    } 

    //REverse the second part of the linked list...
    LinkedListNode<int>*prev=0,*next,*head2;
    
    while(slow){
        next=slow->next;
        slow->next=prev;
        prev=slow;
        slow=next;    
    }
    head2=prev;
    

    while(head&&head2&&head->data==head2->data){
        head=head->next;
        head2=head2->next;
    }

    if(head2)return false;
    return true;
   

}