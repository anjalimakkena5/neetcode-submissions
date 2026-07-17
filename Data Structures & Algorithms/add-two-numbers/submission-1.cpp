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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head1=l1;
        ListNode* head2=l2;
        int sum=0;
        int carry=0;
        ListNode* dnode=new ListNode(-1);
        ListNode* curr=dnode;
        while(head1!=nullptr || head2!=nullptr){
            sum=carry;
            if(head1){
                sum+=head1->val;
                head1=head1->next;
            }
            if(head2){
                sum+=head2->val;
                head2=head2->next;
            }
            carry=sum/10;
            ListNode* newnode=new ListNode(sum%10);
            curr->next=newnode;
            curr=curr->next;
        }
        if(carry){
            ListNode* newNode=new ListNode(carry);
                curr->next=newNode;
                curr=curr->next;
        }
        return dnode->next;
    }
};
