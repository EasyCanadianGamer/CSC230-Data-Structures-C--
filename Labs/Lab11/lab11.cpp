#include <iostream>
#include <stack>
#include <queue>

using namespace std;

// Tree Node has data, left pointer, right pointer
struct TreeNode
{
    int datum;
    struct TreeNode* left;
    struct TreeNode* right;
};

// create a new node with given value, left and right pointers are nullptr
struct TreeNode* newTreeNode(int value)
{
    struct TreeNode* node = new struct TreeNode;
    node->datum = value;
    node->left = nullptr;
    node->right = nullptr;
    return(node);
}

// Non-recursive traverse a binary tree
// print out the values by inorder
// it uses stack to store the nodes 
void noRecInorder(TreeNode *root)
{
    stack<TreeNode*> s; // makes a stack treenode called s
    TreeNode* curr = root; // makes the current pointer of treenode to root
    while(curr!= nullptr ||!s.empty()){ // while the current pointer is not null or the stack is not empty
        while(curr!= nullptr){ // while the current pointer is not null
            s.push(curr); // push the current pointer into the stack
            curr = curr->left; //  move the current pointer to the left
        }
        curr = s.top(); // set the current pointer to the top of the stack
        s.pop(); // pop the top of the stack
        cout << curr->datum << " ";  // print out the datum of the current pointer
        curr = curr->right; // move the current pointer to the right
    }
    cout << endl; // end with a new line

    
}

// level order traversal 
// It uses queue to store the values of the next level
void levelOrder(TreeNode *root)
{
    queue<TreeNode*> q; // make a queue called q
    TreeNode* curr = root; // make the current pointer to root
    q.push(curr); // push the current pointer into the queue
    while(!q.empty()){ // while the queue is not empty
        curr = q.front(); //   set the current pointer to the front of the queue
        q.pop(); // pop the front of the queue
        cout << curr->datum << " "; // print out the datum of the current pointer
        if(curr->left!= nullptr) // if the left pointer is not null
            q.push(curr->left); // push the left pointer into the queue
        if(curr->right!= nullptr) // if the right pointer is not null
            q.push(curr->right); // push the right pointer into the queue
    }
    cout << endl; // end with a new line
}


// Driver program to test above functions
int main()
{
    /* Constructed binary tree is
        100
      /     \
      9      10
     /  \    /
     9   4  7
     */

    struct TreeNode *root = newTreeNode(100);
    root->left        = newTreeNode(9);
    root->right       = newTreeNode(10);
    root->left->left  = newTreeNode(9);
    root->left->right = newTreeNode(4);
    root->right->left = newTreeNode(7);


    cout << "Inorder traversal result:" << endl;;
    noRecInorder(root);
    cout << "Level traversal result:" << endl;
    
    levelOrder(root);
    
    return 0;
}
