/*
Solution Implements both recursive and iterative methods of doing below problem

CCI - 2.5 
Sum Lists: You have two numbers represented by a linked list, where each node contains a single digit.
The digits are stored in reverse order, such that the 1 's digit is at the head of the list.
Write a function that adds the two numbers and returns the sum as a linked list.

EXAMPLE
Input:(7-> 1 -> 6) + (5 -> 9 -> 2).Thatis,617 + 295. Output:2 -> 1 -> 9.Thatis,912.
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

Node* addTwoLLreversed_recursion(Node* n1, Node* n2,int carry) {
    int x1,x2; 
    Node* n1next = NULL;
    Node * n2next = NULL;
    if(!n1) { 
        x1 = 0;
    }else {
        x1 = n1->data;
        n1next = n1->next;
    }
    if(!n2){
        x2 = 0; 
    }else {
        x2 = n2-> data;
        n2next = n2->next;
    }
    if(debug) cout << "x1: " << x1 << "  x2: "<<x2<<"  carry: "<<carry<<"\n";
    int sum = x1 + x2 + carry;
    carry = sum / 10;
    int remainder = sum % 10;
    if(debug) cout <<"sum: "<<sum<< "  new carry:- " << carry <<"  remainder:- "<<remainder<<"\n";
    Node * result = new Node(remainder);
    if(n1next or n2next or carry!=0) 
        result->next = addTwoLLreversed_recursion(n1next,n2next,carry);
    else
        result->next = NULL;
    return result;

}

Node* addTwoLLreversed_iterative(Node* n1,Node* n2) {
    int x1,x2;
    int sum,carry,remainder;
    carry = 0;
    Node * result;

    x1 = n1->data;   //Do entire procedure for 1st node to save head pointer info 
    x2 = n2->data;
    sum = x1 + x2 + carry;
    remainder = sum%10;
    carry = sum/10;
    result = new Node(remainder);
    Node* head = result;
    n1 = n1->next;
    n2 = n2-> next;
    
    while(n1 and n2){
        x1 = n1->data;
        x2 = n2->data;
        sum = x1 + x2 + carry;
        remainder = sum%10;
        carry = sum/10;
        result->next = new Node(remainder);
        result = result->next;
        n1=n1->next;
        n2=n2->next;
    }
    Node * n=NULL;
    if(n1) n = n1;
    else if(n2) n = n2;
    while(n){
        x1 = n->data;
        sum = x1 + carry;
        remainder = sum%10;
        carry = sum/10;
        result->next = new Node(remainder);
        result = result->next;
        n=n->next;
    }
    if(carry) {
        result->next = new Node(carry);
        result = result->next;
    }
    result->next = NULL;
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


    printf("\nOutput:-");  
    SinglyLL LLoup;
    LLoup.head = addTwoLLreversed_recursion(LL1.head,LL2.head,0);
    LLoup.printLL();    

    printf("\nOutput-2:-");  
    SinglyLL LLoup2;
    LLoup2.head = addTwoLLreversed_iterative(LL1.head,LL2.head);
    LLoup2.printLL();    
}
