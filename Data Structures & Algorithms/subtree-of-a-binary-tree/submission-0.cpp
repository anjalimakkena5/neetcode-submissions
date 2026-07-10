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
    bool sametree(TreeNode* p,TreeNode* q)
    {
        if(p==nullptr ||q==nullptr) return p==q;
        if(p->val!=q->val) return false;
        else return sametree(p->left,q->left)&& sametree(p->right,q->right);
    }
    bool func(TreeNode* root, TreeNode* subRoot){
        if(subRoot==nullptr) return true;
        else if(root==nullptr) return false;
        else if(sametree(root,subRoot)) return true;
        else return func(root->left,subRoot)||func(root->right,subRoot);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return func(root,subRoot);
        
    }
};
