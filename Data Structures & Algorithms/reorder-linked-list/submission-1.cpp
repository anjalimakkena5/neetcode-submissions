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
    ListNode* findmiddle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=nullptr;
        while(curr!=nullptr){
            ListNode* front=curr->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* middle=findmiddle(head);
        ListNode* newhead=reverse(middle->next);
        middle->next=nullptr;
        ListNode* t1=head;
        ListNode* t2=newhead;
        while(t2!=nullptr){
            ListNode* front=t1->next;
            ListNode* revfront=t2->next;
            t1->next=t2;
            t2->next=front;
            t1=front;
            t2=revfront;
        }

    }
};
