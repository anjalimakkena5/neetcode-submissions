class Solution {
public:
    bool check(int i,int j,string &s,vector<vector<int>>&dp){
        if(i>=j) return true;
        if(s[i]!=s[j]) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=check(i+1,j-1,s,dp);
    }
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(check(i,j,s,dp)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
