//CCI 2.2 - Implement an algorithm to find the kth to last element of a singly linked list.

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

Node* kthElem(Node * head,int k) {

Node * p1, * p2;
p1 = head;
p2 = head;

for(int i=1;i<=k;i++) {
    p2 = p2->next;
}
while(p2) {
    p1 = p1->next;
    p2 = p2->next;
}
return p1;
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
    int k;
    cout<<"Enter k value\n";
    cin >> k;
    LL1.printLL();
    printf("\nOutput:-");  
    
    Node * kthelem = kthElem(LL1.head,k);
    cout << kthelem->data;
   
}
