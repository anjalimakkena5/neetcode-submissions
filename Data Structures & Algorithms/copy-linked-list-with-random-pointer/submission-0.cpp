/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        //insert new nodes in between
        Node* temp=head;
        while(temp!=nullptr){
            Node* copynode=new Node(temp->val);
            copynode->next=temp->next;
            temp->next=copynode;
            temp=temp->next->next;
        }
        //connect random pointers
        temp=head;
        while(temp!=nullptr){
            Node* copynode=temp->next;
            if(temp->random) copynode->random=temp->random->next;
            else copynode->random=temp->random;
            temp=temp->next->next;
        }
        temp=head;
        Node* dnode=new Node(-1);
        Node* res=dnode;
        while(temp!=nullptr){
            res->next=temp->next;
            temp->next=temp->next->next;
            res=res->next;
            temp=temp->next;
        }
        return dnode->next;

    }
};
