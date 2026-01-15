// User function Template for C++

/*struct Node {
    int data;
    Node *left, *right;
};*/

class Solution {
  public:
    int idx;

    void inorderTraversal(Node* root, vector<int> &inorder)
    {
        if (!root) return;
        inorderTraversal(root->left, inorder);
        inorder.push_back(root->data);
        inorderTraversal(root->right, inorder);
    }

    void postorderFill(Node* root, vector<int> &inorder)
    {
        if (!root) return;

        postorderFill(root->left, inorder);
        postorderFill(root->right, inorder);

        root->data = inorder[idx];
        idx++;
    }
    void convertToMaxHeapUtil(Node* root) {
        // Your code goes here
        vector<int> inorder;
        inorderTraversal(root, inorder);

        idx = 0; // start from largest

        postorderFill(root, inorder);
    }
};
