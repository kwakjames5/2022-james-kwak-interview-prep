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
    vector<vector<int>> return_vec;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> return_vec;
        if(root == nullptr) {
            return return_vec;
        }
        queue<TreeNode*> node_queue;
        node_queue.push(root);
        TreeNode* curr_node;
        int node_queue_size_store;
        
        while(!node_queue.empty()) {
            vector<int> values;
            node_queue_size_store = node_queue.size();
            for(int i = 0; i < node_queue_size_store; i++) {
                curr_node = node_queue.front();
                node_queue.pop();
                values.push_back(curr_node->val);
                
                if(curr_node->left) {
                    node_queue.push(curr_node->left);
                }
                if(curr_node->right) {
                    node_queue.push(curr_node->right);
                }
            }
            return_vec.push_back(values);
        }
        
        return return_vec;
    }
};