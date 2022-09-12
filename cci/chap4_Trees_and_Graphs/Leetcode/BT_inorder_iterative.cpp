//Leetcode - Binary Tree Inorder traversal 
#include <iostream>
using namespace std;
int debug = 0;
#define COUNT 10
#include <stack>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
void inorder_iterative(TreeNode * root) {
    stack<TreeNode *> s;
    TreeNode * curr = root;
    while(curr || !s.empty()){
       while(curr) {
           s.push(curr);
           curr = curr->left;
       }
       curr = s.top();
       s.pop();
       cout << curr->val << "  ";
       curr = curr ->right;
    } 
}

void inorder(TreeNode *root);
void printTree(TreeNode *root);
void print2DUtil(TreeNode *root, int space);
void print2D(TreeNode *root);

int main(int argc,char * argv[]) {


TreeNode *root = new TreeNode(2);
root->left = new TreeNode(1);
root->right = new TreeNode(3);

inorder_iterative(root);
printTree(root);
print2D(root);


root = new TreeNode(5);
root->left = new TreeNode(1);
root->right = new  TreeNode(4);
root->right->left = new TreeNode(3);
root->right->right = new TreeNode(6);

inorder_iterative(root);
printTree(root);
print2D(root);

}
void inorder(TreeNode *root) {

    if(!root) return;

    inorder(root->left);
    cout<< "    "<<root->val;
    inorder(root->right);
    return;
}
void printTree(TreeNode *root) {
    cout<<"\n";
    inorder(root);
    cout<<"\n";
    return;
}
void print2DUtil(TreeNode *root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    cout<<endl;
    for (int i = COUNT; i < space; i++)
        cout<<" ";
    cout<<root->val<<"\n";
 
    // Process left child
    print2DUtil(root->left, space);
}
 
// Wrapper over print2DUtil()
void print2D(TreeNode *root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}