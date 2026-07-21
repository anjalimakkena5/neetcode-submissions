class Twitter {
public:
    int timer;
    unordered_map<int,unordered_set<int>>follows;
    unordered_map<int,vector<pair<int,int>>>tweets;//user,time,tweetid;
    Twitter() {
        timer=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>>pq;
        follows[userId].insert(userId);
        for(auto user:follows[userId]){
            if(tweets[user].empty()){
                continue;
            }
            int idx=tweets[user].size()-1;
            pq.push({
                tweets[user][idx].first,
                tweets[user][idx].second,
                user,
                idx
            });
        }
        vector<int>ans;
        while(!pq.empty() && ans.size()<10){
            auto curr=pq.top();
            pq.pop();
            int tweetId=curr[1];
            int user=curr[2];
            int idx=curr[3];
            ans.push_back(tweetId);
            idx--;
            if(idx>=0){
                pq.push({
                tweets[user][idx].first,
                tweets[user][idx].second,
                user,
                idx
            });
            }
        }
        return ans;
        
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};
