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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
        for(int i=0;i<lists.size();i++){
            pq.push({lists[i]->val,lists[i]});
        }
        ListNode* dnode=new ListNode(-1);
        ListNode* curr=dnode;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            ListNode* temp=it.second;
            curr->next=temp;
            if(temp->next){
                pq.push({temp->next->val,temp->next});
            }
            curr=curr->next;
        }
        return dnode->next;
        
    }
};
