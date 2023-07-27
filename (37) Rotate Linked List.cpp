/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
     // Write your code here.
     Node *tail=head,*newHead= head;
         if(!head) return head;
         int len=1;
         while(tail->next){
              tail=tail->next;
              len++;   
         }
          tail->next=head;
         if(k%=len){
              for(int i=0;i<len-k;i++){
                   tail=tail->next;
              }
              
         }

         newHead=tail->next;
              tail->next=0;

     return newHead;
}