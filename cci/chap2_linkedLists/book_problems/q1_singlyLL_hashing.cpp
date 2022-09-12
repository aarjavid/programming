// CCI 2.1 - Write code to remove duplicates from an unsorted linked list.
//Solution implemented using singly LL and hashing.

#include <iostream>
#include <unordered_set>
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

class SinglyLL {
    Node* head = NULL;
public:
    void insertNodeAtTail(int data);
    void deleteNodeByPtr(Node * prevToDel );
    void printLL();
    Node* extractHeadPtr();
};

void SinglyLL:: insertNodeAtTail(int data) {
    Node * newNode = new Node(data);
    if(head==NULL) { //first node
        head = newNode;
        return;
    }

    Node * temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void SinglyLL::deleteNodeByPtr(Node * prevToDel) {
    if(prevToDel == NULL or prevToDel->next == NULL) { //Handle any error
        cout << "ERROR - trying to delete an non-existing node\n";
        return;
    }

    Node * toDel = prevToDel->next;
    prevToDel->next = toDel->next;
    delete toDel;

}

void SinglyLL::printLL(){
    if(head == NULL) {
        cout << "Empty List\n";
        return;
    }
    printf("\n\nPrinting LL\n");
    Node * temp = head;
    while(temp != NULL) {
        cout << temp->data << "    " ;
        temp = temp -> next;
    }
    cout << "\n";
}

Node* SinglyLL::extractHeadPtr() {
    return head;
}

void removeDuplicatesFromLL(SinglyLL *LLptr) {
    if(debug)  {
        cout << "\nlinked lists elements are:- \n" ;
        LLptr->printLL();
    }

    
    Node * prevPtr = LLptr->extractHeadPtr();  //start of LL (head ptr)
    if(prevPtr->next == NULL) return;
    unordered_set <int>  hashmap;
    int data;
    Node *checkCurNode = prevPtr->next;
    hashmap.insert(prevPtr->data); //inserting 1st element
    while(checkCurNode != NULL) {
        data = checkCurNode->data;
        if(hashmap.find(data) != hashmap.end()) {  //duplicate
            LLptr->deleteNodeByPtr(prevPtr);
            checkCurNode = prevPtr -> next;
        }else {
            hashmap.insert(data); //unique data;
            checkCurNode = prevPtr->next->next;
            prevPtr=prevPtr->next;
        }
    
    }
}

int main (int argc,char* argv[]) {
    if(argc>1) debug = atoi(argv[1]);
    printf("\n\nEnter elements to form a LL.\nEnter -1 when done\n");
    int node_value = 1;
    SinglyLL LL;
    while(true) {
        cin >> node_value;
        if(debug) cout << node_value << "\n";
        if(node_value == -1) break;
        LL.insertNodeAtTail(node_value);
    }
    LL.printLL();
    removeDuplicatesFromLL(&LL);
    printf("\nOutput\n");
    LL.printLL();
    printf("Program over\n\n");
}