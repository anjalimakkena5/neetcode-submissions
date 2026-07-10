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
    TreeNode* func(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==nullptr||p==nullptr||q==nullptr) return root;
        if(p->val<root->val && q->val<root->val){
            return func(root->left,p,q);
        }
        else if(p->val>root->val && q->val>root->val){
            return func(root->right,p,q);
        }
        else{
            return root;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return func(root,p,q);
        
    }
};
