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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        int sum = 0;
        while(!nodeQueue.empty()) {
            int queueSize = nodeQueue.size();
            sum = 0;
            while(queueSize--) {
                TreeNode* curr = nodeQueue.front();
                nodeQueue.pop();
                if(curr->left) {
                    nodeQueue.push(curr->left);
                }
                if(curr->right) {
                    nodeQueue.push(curr->right);
                }
                if(!curr->left && !curr->right) {
                    sum += curr->val;
                }
            }
        }
        return sum;
    }
};