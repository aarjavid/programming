//Implementation of doubly linked lists with functions to insert or delete in LL and print LL. 
#include <iostream>
using namespace std;
int debug = 0;

class Node {
public:
    int data = 0;
    Node * next = NULL;
    Node * prev = NULL;

    Node(int data) { // Constructor
        this -> data = data;
        this -> next = NULL;
        this -> prev = NULL;
    }
};

class DoublyLL {
    Node * head = NULL;
    Node * tail = NULL;
    int DoublyLLlen = 0;

public:
    void insertNodeAtHead(int data);
    void insertNodeAtTail(int data);
    void deleteNodeByIndex(int index);
    void deleteNodeByValue(int value);
    void printLL();
    int calcLLlen();
};

    void DoublyLL :: insertNodeAtHead(int data) {
        Node * newNode = new Node(data);
        DoublyLLlen++;
        if(head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->next = head;
        head -> prev = newNode;
        head = newNode;
        
    }
    void DoublyLL :: insertNodeAtTail(int data){
        Node * newNode = new Node(data);
        DoublyLLlen++;
        if(head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }

        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;

    }
    void DoublyLL :: deleteNodeByIndex(int index){
        if(DoublyLLlen == 0) { //if(head == NULL) //empty list 
            cout << "EMPTY list\n";
            return;
        }
        if(index < 0 & index > DoublyLLlen) {
            cout << "ERROR -  Index out of bounds\n";
            return;
        }
        Node * temp = head;
        if(index==1) {
            head->next->prev = NULL;
            head=head->next;
            DoublyLLlen--;
            delete temp;
            return;
        }
        if(index == DoublyLLlen) {
            temp = tail;
            tail->prev->next = NULL;
            tail = tail->prev;
            DoublyLLlen--;
            delete  temp;
            return;
        }
        int counter = 2;
        while(counter!=index){
            counter++;
            temp = temp->next;
        }
        Node * todel = temp->next;
        todel->next->prev = temp;
        temp->next = todel->next;
        DoublyLLlen--;
        delete todel;
        return;
    }
    void DoublyLL :: deleteNodeByValue(int value){
        if(DoublyLLlen==0){ //if(head==NULL)  //empty list
            cout << "EMPTY list\n";
            return;
        }
        Node * temp = head;
        if(head->data == value) {
            head->next ->prev = NULL;
            head = head->next;
            DoublyLLlen--;
            delete temp;
            return;
        }
        while(temp->next->data != value ) {
            temp = temp->next;
            if(temp->next==NULL){
                cout <<"Value Not found in the list\n"; //Unsuccessful search
                return;
            }
        }
        Node *  todel = temp->next;
        temp->next = todel->next;
        if(todel != tail) {
            todel->next->prev = temp;
        }
        else {
              tail = temp;
        }
        DoublyLLlen--;
        delete todel;      
    }

    void DoublyLL :: printLL(){
        if(head==NULL) {
            cout << "EMPTY list\n";
            return;
        }
        Node * temp = head;
        int counter = 1;
        printf("\n\nPrinting the LL:-\n");

        while(temp!= NULL) {
            cout << "Node Index:- " << counter++ ;
            cout << "   Node Value:- " << temp->data << "\n";
            temp = temp->next;
        }
    }
    int DoublyLL :: calcLLlen(){
        return DoublyLLlen;
    }


int main(int argc,char * argv[]) {

    if(argc>1) debug = atoi(argv[1]);
    DoublyLL DLL;
    DLL.insertNodeAtTail(1);
    DLL.printLL();
    DLL.insertNodeAtTail(2);
    DLL.printLL();
    DLL.insertNodeAtTail(3);
    DLL.printLL();
    DLL.insertNodeAtTail(4);
    DLL.printLL();
    DLL.insertNodeAtTail(5);
    DLL.printLL();
    DLL.insertNodeAtTail(6);
    DLL.printLL();

    DLL.insertNodeAtHead(0);
    DLL.printLL();
    DLL.insertNodeAtHead(-1);
    DLL.printLL();

    DLL.deleteNodeByValue(-1);
    DLL.printLL();
    DLL.deleteNodeByValue(5);
    DLL.printLL();
    DLL.deleteNodeByValue(6);
    DLL.printLL();
    printf("checking this\n");
    DLL.deleteNodeByIndex(2);
    DLL.printLL();
    DLL.deleteNodeByIndex(4);
    DLL.printLL();
    printf("checking this\n");
    DLL.deleteNodeByIndex(1);
    DLL.printLL();
    
}