class Solution {
public:
    bool func(int i,int j,string &s1,string &s2,string &s3,vector<vector<int>>&dp){
        int m=s1.size();
        int n=s2.size();
        int p=s3.size();
        int k=i+j;
        if(i==m && j==n && k==p) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s3[k] && s2[j]==s3[k]){
            return dp[i][j]=func(i+1,j,s1,s2,s3,dp)||func(i,j+1,s1,s2,s3,dp);
        }
        else if(s1[i]==s3[k]){
            return dp[i][j]=func(i+1,j,s1,s2,s3,dp);
        }
        else if(s2[j]==s3[k]){
            return dp[i][j]=func(i,j+1,s1,s2,s3,dp);
        }
        else{
            return dp[i][j]=false;
        }
    }
    bool isInterleave(string s1, string s2, string s3) {
        if((s1.size()+s2.size())!=s3.size()) return false;
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return func(0,0,s1,s2,s3,dp);
        
        
    }
};
