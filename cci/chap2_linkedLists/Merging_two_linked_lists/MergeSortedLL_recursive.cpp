//Recursive program to merge two sorted Linked lists .

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

Node* MergeSortedLL(Node* l1,Node* l2){
    if(!l1) return l2;
    if(!l2) return l1;
    
    if(l1->data<l2->data) {
        l1->next = MergeSortedLL(l1->next,l2);
        return l1;
    }else {
        l2->next = MergeSortedLL(l1,l2->next);
        return l2;
    }
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
        LL1.insertNodeAtTail(node_value);
    }
    printf("Enter elements for 2nd linked list.enter -1 to stop\n");
    SinglyLL LL2;
    
    while(true) {
        cin >> node_value;
        if(debug) cout << node_value<< "\n" ;
        if(node_value==-1) break;
        LL2.insertNodeAtTail(node_value);
    }
    LL1.printLL();
    LL2.printLL();
    
    printf("\nOutput:-");
    if(LL1.head==NULL) LL2.printLL();
    else if(LL2.head == NULL) LL1.printLL();
    LL1.head  = MergeSortedLL(LL1.head,LL2.head);
    LL1.printLL();
   
}

