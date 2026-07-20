class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(auto num:stones){
            pq.push(num);
        }
        pq.push(0);
        while(!pq.empty() && pq.size()!=1){
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            if(x!=y){
                pq.push(x-y);
            }
        }
        return pq.top();
    }
};
