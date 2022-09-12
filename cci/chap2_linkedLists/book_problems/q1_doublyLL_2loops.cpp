// CCI 2.1 - Write code to remove duplicates from an unsorted linked list.
//Solution implemented using doubly LL and brute force technique of 2 for loops.


#include <iostream>
using namespace std;
int debug = 0;
class Node {
public :
    int data = 0;
    Node * next = NULL;
    Node * prev = NULL;

    Node(int data) {
        this->data = data;
        this -> next = NULL;
        this -> prev = NULL;
    }
};

class DoublyLL {
    Node * head = NULL;
    Node * tail = NULL;
public:
    void insertNodeAtTail(int data);
    Node* extractLLhead();
    void printLL();
};

void DoublyLL::insertNodeAtTail(int data){
    Node * newNode = new Node(data);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;

}

Node* DoublyLL::extractLLhead(){
    return head;
}

void DoublyLL::printLL(){
    if(head==NULL) return;
    Node* temp = head;
    printf("Printing LL\n");
    while(temp!=NULL){
        cout <<temp->data <<"   ";
        temp = temp->next;
    }
}

void removeDuplicatesFromLL(DoublyLL *LLptr) {
    Node* ptr1;
    Node * ptr2;
    ptr1 = LLptr->extractLLhead();
    if(ptr1->next == NULL) return; //single element inlist
    Node * temp;
    while(ptr1!=NULL) {
        ptr2 = ptr1->next;
        while(ptr2!=NULL) {
            if(ptr2->data == ptr1->data) {
                ptr2->prev->next = ptr2->next;
                if(ptr2->next==NULL) {
                   // tail = ptr2->prev;
                }
                else{
                    ptr2->next->prev = ptr2->prev;
                }
                temp = ptr2;
                delete temp;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }

}
int main (int argc,char* argv[]) {
    if(argc>1) debug = atoi(argv[1]);
    printf("\n\nEnter elements to form a LL.\nEnter -1 when done\n");
    int node_value = 1;
    DoublyLL LL;
    
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