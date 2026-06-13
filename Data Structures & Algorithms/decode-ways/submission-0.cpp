class Solution {
public:
    int func(int i,string &s,vector<int>&dp){
        int n=s.size();
        if(i==n) return 1;
        if(s[i]=='0') return 0;
        if(dp[i]!=-1) return dp[i];
        int one=func(i+1,s,dp);
        int two=0;
        if(i+1<n){
            if(s[i]=='1'||(s[i]=='2' && s[i+1]<='6')){
                two=func(i+2,s,dp);
            }
        }
        return dp[i]=one+two;
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n+1,-1);
        return func(0,s,dp);

    }
};
