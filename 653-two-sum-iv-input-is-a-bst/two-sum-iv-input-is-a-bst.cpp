/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> st;
    bool reverse = true;
    BSTIterator(TreeNode* root,bool flag) {
        reverse = flag;
        PushAll(root);
        
    }
    
    int next() {
        TreeNode * value = st.top();
        st.pop();
        if(!reverse){
            PushAll(value->right);
        }
        else{
            PushAll(value->left);
        }
        return value->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }

    void PushAll(TreeNode* node){
        while(node!=NULL){
            st.push(node);
            if(reverse)
            node = node->right;
            else
            node = node->left;
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        BSTIterator l(root,false);
        BSTIterator r(root,true);

        int i = l.next();
        int j = r.next();

        while(i<j){
            if(i+j==k) return true;
            else if(i+j<k) i=l.next();
            else j=r.next();
        }
        return false;
    }
};