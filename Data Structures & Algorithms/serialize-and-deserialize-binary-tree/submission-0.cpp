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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        if(root==nullptr) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr==nullptr){
                ans.append("#,");
            }
            else{
               ans.append(to_string(curr->val)+',');
               q.push(curr->left);
               q.push(curr->right);
            }
        }
        return ans;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return nullptr;
        stringstream s(data);
        string str="";
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();

            getline(s,str,',');
            if(str=="#"){
                curr->left=nullptr;
            }
            else{
                TreeNode* leftnode=new TreeNode(stoi(str));
                curr->left=leftnode;
                q.push(curr->left);
            }
            getline(s,str,',');
            if(str=="#"){
                curr->right=nullptr;
            }
            else{
                TreeNode* rightnode=new TreeNode(stoi(str));
                curr->right=rightnode;
                q.push(curr->right);
            }
        }
        return root;
    }
};
