#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    Node<int>*ptr1=first,*ptr2=second,*temp=0;
    if(ptr1==0) return ptr2;
    if(ptr2==0) return ptr1;
    if(ptr1->data>ptr2->data) {
        temp=ptr1;
        ptr1=ptr2;
        ptr2=temp;
    }
    Node<int>*res=ptr1;
    while(ptr1!=0&&ptr2!=0){

        temp=0;

        while(ptr1!=0&&ptr1->data<=ptr2->data) {
            temp=ptr1;
            ptr1=ptr1->next;
        }

        temp->next=ptr2;
        
        //swap the nodes...
        temp=ptr1;
        ptr1=ptr2;
        ptr2=temp;
    }
    return res;
}
