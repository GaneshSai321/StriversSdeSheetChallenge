#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    if(head==0) return 0;
    map<LinkedListNode<int>*,LinkedListNode<int>*>mp;
    LinkedListNode<int>* newHead = new LinkedListNode<int>(head->data);
    mp[head] = newHead;
    LinkedListNode<int>* ptr1 = head, *ptr2 =newHead;
    while(ptr1!=0){
       if(ptr1->next ){
           LinkedListNode<int>*newNextNode = new LinkedListNode<int>(ptr1->next->data);
            ptr2->next = newNextNode;
            mp[ptr1->next] = newNextNode;
       }
        ptr2=ptr2->next;
        ptr1= ptr1->next;
    }

    ptr1=head;
    ptr2=newHead;

    while(ptr1!=0){
       if(ptr1->random){
          ptr2->random = mp[ptr1->random];
       }
       else ptr2->random = 0;
        ptr2=ptr2->next;
        ptr1= ptr1->next;
    }

    return newHead;
}
