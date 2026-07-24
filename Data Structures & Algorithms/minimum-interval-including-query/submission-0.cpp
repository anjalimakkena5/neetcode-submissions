class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(),intervals.end());
        vector<pair<int,int>>q;
        int n=queries.size();
        for(int i=0;i<n;i++){
            q.push_back({queries[i],i});
        }
        sort(q.begin(),q.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int i=0;
        vector<int>res(n);
        for(auto it:q){
            int val=it.first;
            int idx=it.second;
            while(i<intervals.size() && intervals[i][0]<=val){
                int start=intervals[i][0];
                int end=intervals[i][1];
                pq.push({end-start+1,end});
                i++;
            }
            while(!pq.empty() && pq.top().second<val){
                pq.pop();
            }
            res[idx]=pq.empty()?-1:pq.top().first;
        }
        return res;
    }
};
