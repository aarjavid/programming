//Implementation of singly linked lists with functions to insert or delete in LL and print LL. 

#include <iostream>
using namespace std;
int debug = 0;

class Node {
public:
    int data=0;                 //default values
    Node* next=NULL;

    Node(int data) {
        this -> data = data;        //parameterized constructor
        this -> next = NULL;
    }
};

class SinglyLL{
    Node* head = NULL;
    int SinglyLLlen = 0;

public: 
    void insertNodeAtHead(int data);
    void insertNodeAtTail(int data);
    void deleteNodeByValue(int data);
    void deleteNodeByIndex(int index);
    int calcLLlen();
    void printLL();
};

void SinglyLL::insertNodeAtHead(int data) {
    Node* newNode = new Node(data);
    SinglyLLlen++;
    if(head == NULL) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;

}

void SinglyLL::insertNodeAtTail(int data) {
    Node *newNode = new Node(data);
    SinglyLLlen++;
    if(head == NULL) {
        head = newNode;
        if(debug) printf("Its the first node\n");
        return;
    }
    Node * temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return;
}

void SinglyLL::deleteNodeByValue(int data) {
    if(SinglyLLlen==0) {  //if(head==NULL) - empty LL
        cout << "ERROR - Trying to delete from an emtpy linked list\n";
        return;
    }

    Node *temp = head;
    Node * prev;
    while(temp->data != data) {
        prev = temp;
        temp = temp -> next;
        if(temp==NULL) {
            cout << "Value not found in list\n"; //Unsuccessful search;
            return;
        }
    }
    
    SinglyLLlen--;
    if(temp == head) { //delete the head
        head = head -> next;
        delete temp;
        return;
    }

    prev->next = temp-> next;
    delete temp;
}

void SinglyLL::deleteNodeByIndex(int index){
    if(SinglyLLlen==0) { //if(head==NULL) - empty LL
        cout << "ERROR - Trying to delete from an emtpy linked list\n";
        return;
    }

    if(index < 0 or index > SinglyLLlen) {
        cout << "ERROR - Deletion index is greater than length of linked list or less than 0\n";
        return;
    }

    Node * temp = head;
    if(index==1) {  //Delete 1st node
        head = head -> next;
        delete temp;
        SinglyLLlen--;
        return;
    }
    int counter = 1;
    Node * prev ;
    while(counter != index){
        counter++;
        prev = temp;
        temp = temp -> next;
    }
    prev -> next = temp -> next;
    SinglyLLlen--;
    delete temp;

}

int SinglyLL :: calcLLlen() {
    return SinglyLLlen;
}

void SinglyLL :: printLL() {
    Node * temp = head;
    int counter = 1;
    printf("\n\nPrinting the LL:-\n");
    while(temp != NULL) {
        cout << "LL index:- "<< counter++ << "LL data:- " << temp->data << "\n";
        temp = temp -> next;
   }
}

int main(int argc,char * argv[]) {

    if(argc>1) debug = atoi(argv[1]);
    SinglyLL SLL;
    SLL.insertNodeAtTail(1);
    SLL.printLL();
    SLL.insertNodeAtTail(2);
    SLL.printLL();
    SLL.insertNodeAtTail(3);
    SLL.printLL();
    SLL.insertNodeAtTail(4);
    SLL.printLL();
    SLL.insertNodeAtTail(5);
    SLL.printLL();
    SLL.insertNodeAtTail(6);
    SLL.printLL();

    SLL.insertNodeAtHead(0);
    SLL.printLL();
    SLL.insertNodeAtHead(-1);
    SLL.printLL();

    SLL.deleteNodeByValue(-1);
    SLL.printLL();
    SLL.deleteNodeByValue(5);
    SLL.printLL();
    SLL.deleteNodeByValue(6);
    SLL.printLL();
    printf("checking this\n");
    SLL.deleteNodeByIndex(2);
    SLL.printLL();
    SLL.deleteNodeByIndex(4);
    SLL.printLL();
    printf("checking this\n");
    SLL.deleteNodeByIndex(1);
    SLL.printLL();
    
}