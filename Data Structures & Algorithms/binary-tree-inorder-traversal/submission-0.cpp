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
    vector<int> result;

    vector<int> inorderTraversal(TreeNode* root) {
        orderNode(root);
        return result;
    }

    void orderNode(TreeNode* node){
        if(!node)
            return;
        
        orderNode(node->left);
        result.push_back(node->val);
        orderNode(node->right);
    }
};