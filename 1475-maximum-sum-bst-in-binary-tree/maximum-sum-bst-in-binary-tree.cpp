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
class Solution {
public:
    // returns {isBST, minVal, maxVal, sum}
    vector<int> solve(TreeNode* root, int &ans){
        if(!root)
            return {1, INT_MAX, INT_MIN, 0};

        auto left  = solve(root->left, ans);
        auto right = solve(root->right, ans);

        // check BST validity
        if(left[0] && right[0] && root->val > left[2] && root->val < right[1]){
            int currSum = left[3] + right[3] + root->val;
            ans = max(ans, currSum);

            return {
                1,
                min(root->val, left[1]),
                max(root->val, right[2]),
                currSum
            };
        }

        // Not BST then return invalid range
        return {0, INT_MIN, INT_MAX, 0};
    }

    int maxSumBST(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};