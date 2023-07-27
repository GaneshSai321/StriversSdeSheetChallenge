/****************************************************************

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


*****************************************************************/

Node *firstNode(Node *head)
{
    //    Write your code here.
    Node* fast=head,*slow=head;
    while(fast!=0&&fast->next!=0){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            fast=head;
            while(fast!=slow){
                fast=fast->next;
                slow=slow->next;
            }
            return fast;
        }
    }
    return 0;
}