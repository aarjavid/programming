/*
CCI 2.8
Given a circular linked list, implement an algorithm that returns the node at the beginning of the loop.

DEFINITION
Circular linked list: A (corrupt) linked list in which a node's next pointer points to an earlier node, so as to make a loop in the linked list.
EXAMPLE
Input: A -> B -> C -> D -> E -> C[thesameCasearlier]
Output: C
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

Node* startNodeOfLoop(Node * head) {
    Node * slow = head;
    Node* fast = head;

    while(fast and fast->next) {
       
        slow = slow->next;
        fast = fast->next->next;
        if(fast == NULL or fast->next == NULL) return NULL;
        if(fast == slow) break; //loop detected
    }
    slow = head;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    return slow;

}
/* Driver program to test above function*/
// https://www.geeksforgeeks.org/find-first-node-of-loop-in-a-linked-list/
int main()
{
    Node* head = new Node(50);
    head->next = new Node(20);
    head->next->next = new Node(15);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(10);
 
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;
 
    Node* res = startNodeOfLoop(head);
    if (res == NULL)
        cout << "Loop does not exist";
    else
        cout << "Loop starting node is " << res->data;
    return 0;
}
