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
    TreeNode* func(int &i,int start,int end,vector<int>& preorder, vector<int>& inorder,map<int,int>&mpp){
        if(start>end) return nullptr;
        int rootval=preorder[i++];
        TreeNode* root=new TreeNode(rootval);
        int pos=mpp[rootval];
        root->left=func(i,start,pos-1,preorder,inorder,mpp);
        root->right=func(i,pos+1,end,preorder,inorder,mpp);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mpp;
        int n=preorder.size();
        for(int i=0;i<n;i++){
            mpp[inorder[i]]=i;
        }
        int i=0,start=0,end=n-1;
        return func(i,start,end,preorder,inorder,mpp);
    }
};
