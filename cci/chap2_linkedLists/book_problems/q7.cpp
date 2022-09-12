/*
CCI 2.7
Given two (singly) linked lists, determine if the two lists intersect. 
Return the inter­ secting node. Note that the intersection is defined based on reference, not value.
That is, if the kth node of the first linked list is the exact same node (by reference) as the jth node of the second linked list, then they are intersecting.
*/

#include<iostream>
using namespace std;
#include <unordered_set>
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

void printLL(Node* head){
    Node* temp = head;
    printf("\n");
    while(temp) {
        cout << temp->data << "  ";
        temp=temp->next;
    }
}
Node* getIntesectionNode_Hash(Node* n1,Node* n2) {
    Node* temp1 = n1;
    Node* temp2 = n2;
    unordered_set <Node*> hash;
    while(temp1) {
        hash.insert(temp1);
        temp1=temp1->next;
    }
    while(temp2){
        if(hash.find(temp2) != hash.end()) return temp2;
        temp2=temp2->next;
    }
    return NULL;
}
Node* getIntesectionNode_LLlen(Node* n1,Node* n2) {
    Node* temp1 = n1;
    Node* temp2 = n2;
    int len1 = 1;
    int len2 = 1;
    while(temp1->next) {
        len1++;
        temp1=temp1->next;        
    }
    while(temp2->next) {
        len2++;
        temp2=temp2->next;        
    }
    if(temp1!=temp2) return NULL; //last nodes must be equal for intersection

    int offset = 0;
    temp1 = n1;
    temp2 = n2;
    if(len1>len2) {
        offset = len1 - len2;  
        while(offset--) {
            temp1=temp1->next;
        }
    }else if(len2 > len1) {
        offset = len2 - len1;
        while(offset--) {
            temp2=temp2->next;
        }
    }
    while(temp1) {
        if(temp1==temp2) return temp1;
        temp1=temp1->next;
        temp2=temp2->next;
    }
}
//https://www.geeksforgeeks.org/write-a-function-to-get-the-intersection-point-of-two-linked-lists/
// Driver Code
int main()
{
    /*
        Create two linked lists
     
        1st 3->6->9->15->30
        2nd 10->15->30
     
        15 is the intersection point
    */
 
    Node* newNode;
 
    // Addition of new nodes
    Node* head1 = new Node(10);
   
 
    Node* head2 = new Node(3);

 
    newNode = new Node(6);

    head2->next = newNode;
 
    newNode = new Node(9);
   
    head2->next->next = newNode;
 
    newNode = new Node(15);
    
    head1->next = newNode;
    head2->next->next->next = newNode;
 
    newNode = new Node(30);
   
    head1->next->next = newNode;
 
    head1->next->next->next = NULL;
    
    Node* intersection = getIntesectionNode_LLlen(head1, head2);
    cout << "The node of intersection is " << intersection << "  value is :- " <<intersection->data <<"\n";

    Node* intersection2 = getIntesectionNode_Hash(head1, head2);
    cout << "The node of intersection is " << intersection2 << "  value is :- " <<intersection2->data <<"\n";
}
 
