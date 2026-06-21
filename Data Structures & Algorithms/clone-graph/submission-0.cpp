/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr) return node;
        unordered_map<Node*,Node*>mpp;
        Node* clone_node=new Node(node->val);
        mpp[node]=clone_node;
        queue<Node*>q;
        q.push(node);
        while(!q.empty()){
            Node* node=q.front();
            Node* clone_node=mpp[node];
            q.pop();
            for(auto n:node->neighbors){
                if(mpp.find(n)==mpp.end()){
                    Node* clone=new Node(n->val);
                    mpp[n]=clone;
                    clone_node->neighbors.push_back(clone);
                    q.push(n);
                }
                else{
                    clone_node->neighbors.push_back(mpp[n]);
                }
            }
        }
        return mpp[node];

    }
};
