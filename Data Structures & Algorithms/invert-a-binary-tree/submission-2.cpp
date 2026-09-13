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
    TreeNode* func(TreeNode* root){
        if(root==nullptr) return root;
        TreeNode* node=new TreeNode(root->val);
        if(root->left){
            node->right=func(root->left);
        }
        if(root->right){
            node->left=func(root->right);
        }
        return node;
    }
    TreeNode* invertTree(TreeNode* root) {
        return func(root);
        
    }
};
