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

Node* removeDups(Node* head){
    if(!head) return head;
    Node * p1 = head;
    Node* p2=p1->next;
    Node * temp;
    while(p2){
        if(p1->data==p2->data){
            temp = p2;
            p2 = p2->next;
            p1->next = p2;
            delete temp;
        }else {
            p1 = p1->next;
            p2= p2->next;
        }     
    }
    return head;
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
   
    LL1.printLL();
    printf("\nOutput:-");  
    
    SinglyLL LL_oup;
    LL_oup.head = removeDups(LL1.head);
    LL_oup.printLL();
   
}
