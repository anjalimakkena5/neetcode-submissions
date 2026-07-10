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
    bool func(TreeNode* root,long long mini,long long maxi){
        if(root==nullptr) return true;
        if(root->val<=mini || root->val>=maxi) return false;
        else{
            return func(root->left,mini,root->val) && func(root->right,root->val,maxi);
        }
            
        
    }
    bool isValidBST(TreeNode* root) {
        return func(root,LLONG_MIN,LLONG_MAX);
    }
};
