//LeetCode - Validate Binary Search Tree
#include <iostream>
using namespace std;
int debug = 0;
#define COUNT 10;
#include<cmath>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    bool isValidBST_helper(TreeNode * root,int * prev_data) {
        if(!root) return true;
        if(!isValidBST_helper(root->left,prev_data)) return false;
        if(*prev_data > root->val) return false;
        *prev_data = root->val;
        if(!isValidBST_helper(root->right,prev_data)) return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        int prev_data = -1;
        return isValidBST_helper(root,&prev_data);
    }
    
};

void inorder(TreeNode *root);
void printTree(TreeNode *root);
void print2DUtil(TreeNode *root, int space);
void print2D(TreeNode *root);

int main(int argc,char * argv[]) {

Solution s1;
TreeNode *root = new TreeNode(2);
root->left = new TreeNode(1);
root->right = new TreeNode(3);

printTree(root);
print2D(root);
bool validBST = s1.isValidBST(root);
if(validBST) cout << "true\n";
else cout <<"false\n";

root = new TreeNode(5);
root->left = new TreeNode(1);
root->right = new  TreeNode(4);
root->right->left = new TreeNode(3);
root->right->right = new TreeNode(6);

printTree(root);
print2D(root);
validBST = s1.isValidBST(root);
if(validBST) cout << "true\n";
else cout <<"false\n";

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