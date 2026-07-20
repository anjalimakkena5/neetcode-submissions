class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>>pq;
        for(auto num:points){
            int dist=num[0]*num[0]+num[1]*num[1];
            pq.push({dist,{num[0],num[1]}});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>>res;
        while(!pq.empty()){
            res.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        return res;
    }
};
