//LeetCode - Binary Tree Zigzag Level Order Traversal
//Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).


#include <iostream>
using namespace std;
int debug = 0;
#define COUNT 10
#include <stack>
#include <vector>
#include <queue>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        int parent_count  = 1;
        int child_count = 0;
        vector<vector<int> > v1;
        queue<TreeNode *> q;
        q.push(root);
        TreeNode * front;
        if(!root) return v1;
        vector<int> v2;
        int direction = 0;
        while(!q.empty()) {
            cout <<"\n\nnew level";
            while(parent_count>0) {
                front = q.front();
                q.pop();
                cout <<"\npc="<<parent_count<<"  val="<<front->val;
                parent_count--;
                v2.push_back(front->val);
                cout << "debug - direction is =" << direction <<"\n";
                if(direction) {
                    cout <<"left-right , direct=1\n";
                    if(front->left) {
                        q.push(front->left); child_count++;
                    }
                    if(front->right) {
                        q.push(front->right); child_count++;
                    }
                }else {
                    cout <<"right-left , direct=0\n";
                     if(front->right) {
                        q.push(front->right); child_count++;
                    }
                    if(front->left) {
                        q.push(front->left); child_count++;
                    }
                }
            }
            parent_count = child_count;
            child_count = 0;
            v1.push_back(v2);
            v2.clear();
            direction = 1 - direction;
        }
        
    return v1;           
}
void printTree(TreeNode *root);
void print2DUtil(TreeNode *root, int space);
void print2D(TreeNode *root);

int main(int argc,char * argv[]) {

vector<vector<int> > v;
TreeNode *root = new TreeNode(2);
root->left = new TreeNode(1);
root->right = new TreeNode(3);



print2D(root);
v = zigzagLevelOrder(root);
//cout << v;

root = new TreeNode(5);
root->left = new TreeNode(1);
root->right = new  TreeNode(4);
root->right->left = new TreeNode(3);
root->right->right = new TreeNode(6);


print2D(root);
v = zigzagLevelOrder(root);
//cout << v;

root = new TreeNode(1);
root->left = new TreeNode(2);
root->right = new  TreeNode(3);
root->left->left = new TreeNode(4);
root->right->right = new TreeNode(5);


print2D(root);
v = zigzagLevelOrder(root);
////cout << v;
for(auto i : v){
    for(auto j : i)
        cout << j ;
    cout <<"\n";
}


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