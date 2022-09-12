/*CCI - 2.4 
Write code to partition a linked list around a value x, such that all nodes less than x come before all nodes greater than or equal to x. 
If x is contained within the list, the values of x only need to be after the elements less than x (see below). 
The partition element x can appear anywhere in the "right partition"; it does not need to appear between the left and right partitions.

EXAMPLE
Input: 3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1[partition=5] Output: 3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8
*/
#include<iostream>
using namespace std;
int debug = 0;

class Node {
public:
    int data = 0;
    Node* next = NULL;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class SinglyLL{
public:
    Node* head=NULL;
    void printLL(){
        Node* temp = head;
        printf("\n");
        while(temp) {
            cout << temp->data << "  ";
            temp=temp->next;
        }
    }

    void insertNodeAtTail(int data){
        Node * newNode = new Node(data);
        if(!head) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while(temp->next){
            temp=temp->next;
        }
        temp->next = newNode;
    }
};

Node* PartitionLL(Node * head, int x) {
    Node * right = NULL;
    Node * left = NULL;
    Node * temp = head;
    Node* tempnext = NULL;
    Node * leftend;

    while(temp) {
        tempnext = temp -> next;
        if(temp->data>=x) {
            if(!right) {
                right = temp;
                right->next = NULL;
            }else{
                temp->next = right;
                right = temp;
            }
        }else{
            if(!left){
                left = temp;
                left -> next = NULL;
                leftend = left;
            }else{
                temp->next = left;
                left = temp;
            }
        }
        temp=tempnext;
    }
    if(!left) return right;
    leftend->next = right;
    return left;

}

int main(int argc, char * argv[]) {
    if(argc>1) debug = atoi(argv[1]);
    printf("Enter elements for the linked list.enter -1 to stop\n");
    int node_value = 1;
    SinglyLL LL1;
    while(true) {
        cin >> node_value;
        if(debug) cout <<node_value<< "\n" ;
        if(node_value==-1) break;
        LL1.insertNodeAtTail(node_value);
    }
    int x;
    cout<<"Enter Partition value\n";
    cin >> x;
    LL1.printLL();
    printf("\nOutput:-");  
    
    LL1.head = PartitionLL(LL1.head,x);
    LL1.printLL();
   
}
