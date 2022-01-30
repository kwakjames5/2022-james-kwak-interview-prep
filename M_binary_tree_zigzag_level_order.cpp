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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL) {
            return vector<vector<int>> ();
        }
        vector<vector<int>> return_result;
        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);
        bool leftToRight = true;
        
        while(!nodesQueue.empty()) {
            int queueSize = nodesQueue.size();
            vector<int> row(queueSize);
            for(int i = 0; i < queueSize; i++) {
                TreeNode* node = nodesQueue.front();
                nodesQueue.pop();
                int index;
                if(leftToRight) {
                    index = i;
                } else {
                    index = queueSize - i - 1;
                }
                row[index] = node->val;
                if(node->left) {
                    nodesQueue.push(node->left);
                }
                if(node->right) {
                    nodesQueue.push(node->right);
                }
            }
            leftToRight = !leftToRight;
            return_result.push_back(row);
        }
        return return_result;
    }
};