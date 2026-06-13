class Solution {
public:
    bool func(int ind,string &s,unordered_set<string>&st,vector<int>&dp){
        int n=s.size();
        if(ind==n) return true;
        if(st.find(s)!=st.end()) return true;
        if(dp[ind]!=-1) return dp[ind];
        for(int l=1;l+ind<=n;l++){
            if(st.find(s.substr(ind,l))!=st.end() && func(ind+l,s,st,dp)){
                return dp[ind]=true;
            }
        }
        return dp[ind]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        unordered_set<string>st;
        for(auto it:wordDict){
            st.insert(it);
        }
        vector<int>dp(n+1,-1);
        return func(0,s,st,dp);
    }
};
