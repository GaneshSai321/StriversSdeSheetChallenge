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

Node* findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    Node * ptr1=firstHead,*ptr2=secondHead;
    while(ptr1!=ptr2){
        if(ptr1==0&&ptr2==0) return 0;
        ptr1=(ptr1==NULL)?secondHead:ptr1->next;
        ptr2=(ptr2==NULL)?firstHead:ptr2->next;
    }
    return ptr1;
}