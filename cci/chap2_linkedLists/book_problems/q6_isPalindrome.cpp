//CCI 2.6 Implement a function to check if a linked list is a palindrome.
#include<iostream>
using namespace std;
#include <stack>
#include <vector>

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

//method 1 
bool isPalindrome_stack(Node* head){
    stack <int> s;
    Node* temp = head;
    while(temp){
        s.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp){
        int i = s.top();
        s.pop();
        if(i!=temp->data) return false;
        temp=temp->next;
    }
    return true;
}
//---method 1 over

//method 2 starts -
bool isPalindrome_recursionUtil(Node** left,Node* right){
    if(right==NULL) return true;
    bool isPalin = isPalindrome_recursionUtil(left,right->next);
    if(isPalin==false) return false;

    isPalin = (*left)->data == right->data;
    *left=(*left)->next;
    return isPalin;
}

bool isPalindrome_recursion(Node* head) {
    return isPalindrome_recursionUtil(&head,head);
}
// method 2 over

//method 3 starts
bool isPalindrome_array(Node* head) {
    Node * temp = head;
    vector <int> v ;
    while(temp) {
        v.push_back(temp->data);
        temp = temp->next;
    }
    int size = v.size();
    for(int i = 0,j=size-1;i<=j;i++,j--) {
        if(debug) printf("i=%d,j=%d\n",i,j);
        if(v[i]!=v[j]) return false;

    }
    return true;
}

// method 3 over

//method 4 starts
Node* findMidNode(Node * head) {
    Node * slow = head;
    Node * fast = head->next;

    while(fast and fast->next) {
        slow = slow->next;
        fast = fast -> next -> next;
    }
    if(debug) cout << "fast ptr is :- " << fast << "\n";
    return slow;
}

void printList(Node * head){
    Node* temp = head;
    printf("\n");
    while(temp) {
        cout << temp->data << "  ";
        temp=temp->next;
    }
}

void reverseSecondHalf(Node ** second_half) {
    Node * p1 = * second_half;
    Node * p2 = p1->next;
    p1->next = NULL;
    Node * p2next;
    while(p2) {
        p2next = p2 -> next;
        p2 -> next = p1;
        p1 = p2;
        p2 = p2next;
    }
    *second_half = p1;
}



bool isPalindrome_reverseLL(Node* head) {
    Node * midNode = findMidNode(head); 
    if(debug) cout << "\nmidnode is :- " << midNode->data << "\n";  
    Node * second_half = midNode->next;
    reverseSecondHalf(&second_half);
    if(debug) printList(second_half);
    Node * p1 = head;
    Node * p2 = second_half;
    bool isPalin =  true;
    while(p2) {
        if(p1->data != p2->data) {
            isPalin = false;
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    reverseSecondHalf(&second_half);  //reversing second half to maintain original order
    if(debug) printList(second_half);
    midNode->next = second_half;
    if(debug) printList(head);
    return isPalin;
}

//method 4 over
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
    int x;
    
    LL1.printLL();
    printf("\nOutput:-\n");  
    cout << "stack  "  << isPalindrome_stack(LL1.head)<<"\n"; 
    cout << "recur  "  << isPalindrome_recursion(LL1.head)<<"\n";
    cout << "vector  "  << isPalindrome_array(LL1.head)<<"\n";
    cout << "reversal: " << isPalindrome_reverseLL(LL1.head) << "\n";
   
}
