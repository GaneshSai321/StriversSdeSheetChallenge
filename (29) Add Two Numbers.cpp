/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *num1, Node *num2)
{
    // Write your code here.
    int carry=0;
    Node* head=new Node(-1);
    Node*ptr=head;
    while(num1!=0&&num2!=0){
        Node* temp=new Node();
        temp->data=(carry+num1->data+num2->data)%10;
        carry=(carry+num1->data+num2->data)/10;
        ptr->next=temp;
        ptr=temp;
        num1=num1->next;
        num2=num2->next;
    }
    
    if(num1!=0){
        while(num1!=0){
        Node* temp=new Node();
        temp->data=(carry+num1->data)%10;
        carry=(carry+num1->data)/10;
        ptr->next=temp;
        ptr=temp;
        num1=num1->next;
        }
    }

    if(num2!=0){
        while(num2!=0){
        Node* temp=new Node();
        temp->data=(carry+num2->data)%10;
        carry=(carry+num2->data)/10;
        ptr->next=temp;
        ptr=temp;
        num2=num2->next;
        }
    }

    if(carry!=0){
        Node* temp=new Node();
        temp->data=carry;
        ptr->next=temp;
    }

    return head->next;
}
