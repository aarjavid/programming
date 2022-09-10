//Program to merge two sorted Linked lists in place.
#include <iostream>
using namespace std;
int debug = 0;

class Node {
public :
    int data=0;
    Node* next = NULL;

    Node(int data) {
        this->data = data;
        this->next=NULL;
    }
};

class SinglyLL{
public:
    Node * head = NULL;
public:
    void printLL();
    void insertNodeAtHead(int data) ;

    

};

void SinglyLL::printLL() {
    if(head==NULL) return;
    printf("\nPrinting LL\n");
    Node* temp = head;
    while(temp) {
        cout << temp->data << "   ";
        temp=temp->next;
    }
}

void SinglyLL::insertNodeAtHead(int data) {
    Node * newNode = new Node(data);
    if(head==NULL) {
        head = newNode;
        return;
    }
    newNode -> next = head;
    head = newNode;
}

Node* MergeSortedLL(Node* l1,Node* l2) { //passing and returning head pointers 
    Node * cur1,*cur2,*prev1,*prev2;
    cur1 = l1;
    cur2 = l2;
    while(cur1!=NULL and cur2!=NULL) {
        if(cur1->data<=cur2->data) {
            prev1 = cur1;
            cur1 = cur1->next;
            continue;
        }
        prev2= cur2;
        cur2 = cur2->next;
        prev1->next = prev2;
        prev2->next = cur1;
        prev1 = prev2;
    }
    if(cur1==NULL and cur2!=NULL) {
        prev1->next = cur2;
    }
    return l1;
}

int main(int argc, char * argv[]) {
    if(argc>1) debug = atoi(argv[1]);
    printf("Enter elements for 1st linked list.enter -1 to stop\n");
    int node_value = 1;
    SinglyLL LL1;
    while(true) {
        cin >> node_value;
        if(debug) cout <<node_value<< "\n" ;
        if(node_value==-1) break;
        LL1.insertNodeAtHead(node_value);
    }
    printf("Enter elements for 2nd linked list.enter -1 to stop\n");
    SinglyLL LL2;
    
    while(true) {
        cin >> node_value;
        if(debug) cout << node_value<< "\n" ;
        if(node_value==-1) break;
        LL2.insertNodeAtHead(node_value);
    }
    LL1.printLL();
    LL2.printLL();
    
    printf("\nOutput:-");
    if(LL1.head==NULL) LL2.printLL();
    else if(LL2.head == NULL) LL1.printLL();
    if(LL1.head->data <= LL2.head->data) {
        LL1.head  = MergeSortedLL(LL1.head,LL2.head);
        LL1.printLL();
    }
    else {
        LL2.head  = MergeSortedLL(LL2.head,LL1.head);
        LL2.printLL();
    }
}

