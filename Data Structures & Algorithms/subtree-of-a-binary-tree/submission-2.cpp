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
   bool identical(TreeNode* root, TreeNode* subRoot){
    if(root==nullptr || subRoot==nullptr) return root==subRoot;
    if(root->val!=subRoot->val){
        return false;
    }
    else{
        return identical(root->left,subRoot->left) &&identical(root->right,subRoot->right);
    }
   }
   bool check(TreeNode* root, TreeNode* subRoot){
    if(subRoot==nullptr) return true;
    else if(root==nullptr) return false;
    else if(identical(root,subRoot)) return true;
    else{
        return check(root->left,subRoot)||check(root->right,subRoot);
    }
   }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return check(root,subRoot);

        
    }
};
