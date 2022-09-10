//Mergesort for two LL
#include<iostream>
using namespace std;
int debug = 0;

class Node{
public:
    int data = 0;
    Node* next = NULL;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class SinglyLL{
public:
    Node * head = NULL;
    void printLL(){
        Node* temp = head;
        printf("\n");
        while(temp){
            cout << temp->data << "  ";
            temp = temp->next;
        }
    }

    void insertNodeAtTail(int data){
        Node* newNode = new Node(data);
        if(!head){
            head = newNode;
            return;
        }

        Node* temp = head;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = newNode;
    }
};



Node* calcMidPoint(Node* head){
    Node* fast = head->next;
    Node * slow = head;
    while(!fast){
        fast=fast->next;
        if(!fast){
            fast=fast->next;
            slow=slow->next;
        }
    }
    Node* b=slow->next;
    slow->next=NULL;
    return b;
}

Node* MergeSortedLL(Node* l1,Node* l2){
    if(!l1) return l2;
    if(!l2) return l1;
    if(l1->data < l2->data) {
        l1->next = MergeSortedLL(l1->next,l2);
        return l1;
    }else{
        l2->next=MergeSortedLL(l1,l2->next);
        return l2;
    }
}
Node* myMergeSort(Node* head) {
     if ((head == NULL) || (head->next == NULL)) {
        return head;
    }
    Node* a= head;
    Node* b = calcMidPoint(head);
    a = myMergeSort(a);
    b = myMergeSort(b);
    head = MergeSortedLL(a,b);
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
    LL_oup.head = myMergeSort(LL1.head);
    LL_oup.printLL();
   
}



