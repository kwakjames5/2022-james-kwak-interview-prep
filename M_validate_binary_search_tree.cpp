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
    std::vector<int> node_value_vec;
public:
    void dfs_helper(TreeNode* root) {
        if(root == nullptr) {
            return; // Base case
        }
        dfs_helper(root->left);
        node_value_vec.push_back(root->val);
        dfs_helper(root->right);
    }
    
    bool isValidBST(TreeNode* root) {
        dfs_helper(root);
        
        for(int i = 0; i < node_value_vec.size() - 1; i++) {
            if(node_value_vec[i] >= node_value_vec[i + 1]) {
                return false;
            }
        }
        
        return true;
    }
};