/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    string serialize(TreeNode* root) {
        if(!root) return "";
        string s;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            s += to_string(cur->val) + ",";
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        return s;
    }

    TreeNode* insertBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        if(val < root->val) root->left = insertBST(root->left, val);
        else root->right = insertBST(root->right, val);
        return root;
    }

    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;

        vector<int> arr;
        string temp = "";
        for(char c : data) {
            if(c == ',') {
                arr.push_back(stoi(temp));
                temp = "";
            } else temp += c;
        }

        TreeNode* root = NULL;
        for(int x : arr)
            root = insertBST(root, x);

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;