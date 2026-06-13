class Solution {
public:
    bool ispalindrome(int i,int j,string &s,vector<vector<int>>&dp){
        if(i>=j) return true;
        if(s[i]!=s[j]) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=ispalindrome(i+1,j-1,s,dp);
    }
    string longestPalindrome(string s) {
        int n=s.size();
        int start=0;
        int maxlen=1;
        
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                
                if(ispalindrome(i,j,s,dp)){
                    int len=j-i+1;
                    if(len>maxlen){
                        maxlen=len;
                        start=i;
                    }
                    
                }
            }
        }
       return  s.substr(start,maxlen);
    }
};
