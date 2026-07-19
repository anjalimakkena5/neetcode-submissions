/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* find(ListNode* head,int k){
        ListNode* temp=head;
        int cnt=0;
        while(temp!=nullptr){
            cnt++;
            if(cnt==k){
                return temp;
            }
            temp=temp->next;
        }
        return nullptr;
    }
    void reverse(ListNode* head){
        ListNode* prev=nullptr;
        ListNode* curr=head;
        while(curr!=nullptr){
            ListNode* front=curr->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }
        
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* newhead;
        ListNode* prevNode;
        while(temp!=nullptr){
            ListNode* kthnode=find(temp,k);
            if(kthnode==nullptr){
                prevNode->next=temp;
                break;
            }
            ListNode* nextnode=kthnode->next;
            kthnode->next=nullptr;
            reverse(temp);
            if(temp==head){
                newhead=kthnode;
            }
            else{
                prevNode->next=kthnode;
            }
            prevNode=temp;
            temp=nextnode;
        }
        return newhead;
        


    }
};
