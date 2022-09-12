/*
Solution Implements recursive method of doing below problem. 
There are two parameters that has to be passed in recursive solution. So this implementation passes one value by pointer as function parameter and returns another value.


CCI - 2.5
Sum Lists: You have two numbers represented by a linked list, where each node contains a single digit.
Write a function that adds the two numbers and returns the sum as a linked list.
The digits are stored in forward order. 

EXAMPLE
Input:(6 -> 1 -> 7) + (2 -> 9 -> 5).That is,617 + 295. Output:9 -> 1 -> 2.Thatis,912.
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


void zeropadding(Node** n1,Node** n2) {
    int len1=0;
    int len2 = 0;
    Node* temp = *n1;
    while(temp) {
        len1++;
        temp=temp->next;
    }
    temp = *n2;
    while(temp) {
        len2++;
        temp=temp->next;
    }
    if(len1==len2) {return;}
    if(len1<len2) {
        int offset = len2-len1;
        for(int i = 0;i<offset;i++) {
            Node* newNode = new Node(0);
            newNode->next = *n1;
            *n1 = newNode;
        }
    }else {
        int offset = len1-len2;
        for(int i = 0;i<offset;i++) {
            Node* newNode = new Node(0);
            newNode->next = *n2;
            *n2 = newNode;
        }
    }
}


Node* addTwoLL(Node* n1,Node * n2,int* carry_ref){

    int x1 = 0;
    int x2=0;
    Node* n1next = NULL;
    Node* n2next=NULL;
    if(n1) {    //because of padded zeros, both the linked lists n1 and n2 will have same length
        x1 = n1->data;
        n1next = n1->next;
        x2 = n2->data;
        n2next = n2->next;
    }
    int sum;
    int carry=0;

    Node* result = new Node(0);
    if(n1next) {
        result->next = addTwoLL(n1next,n2next,&carry);
    } else result->next = NULL;

    sum = x1 + x2 + carry;
    *carry_ref = sum/10;
    int remainder = sum % 10;
    result->data = remainder;
    return result;
}

Node* addTwoLL_main(Node* n1,Node* n2) {
    int carry=0;
    Node* head = addTwoLL(n1,n2,&carry);
    if(carry) {
        Node* newNode = new Node(carry);
        newNode->next = head;
        head=newNode;
    }
    return head;
}

int main(int argc, char * argv[]) {
    if(argc>1) debug = atoi(argv[1]);
    printf("Enter elements for the 1st linked list.enter -1 to stop\n");
    int node_value = 1;
    SinglyLL LL1;
    while(true) {
        cin >> node_value;
       // if(debug) cout <<node_value<< "\n" ;
        if(node_value==-1) break;
        LL1.insertNodeAtTail(node_value);
    }
    
    printf("Enter elements for 2nd linked list.enter -1 to stop\n");
    SinglyLL LL2;
    
    while(true) {
        cin >> node_value;
        //if(debug) cout << node_value<< "\n" ;
        if(node_value==-1) break;
        LL2.insertNodeAtTail(node_value);
    }
    LL1.printLL();
    LL2.printLL();

    printf("Zeropadding output:-\n");
    zeropadding(&LL1.head,&LL2.head);
    LL1.printLL();
    LL2.printLL();


    printf("\nOutput:-");  
    SinglyLL LLoup;
    LLoup.head = addTwoLL_main(LL1.head,LL2.head);
    LLoup.printLL();    

    
}
