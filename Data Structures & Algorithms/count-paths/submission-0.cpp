class Solution {
public:
    int func(int i,int j,int m,int n,vector<vector<int>>&dp){
        if(i>m ||j>n) return 0;
        if(i==m && j==n) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        int maxi=0;
        int down=func(i+1,j,m,n,dp);
        int right=func(i,j+1,m,n,dp);
        return dp[i][j]=down+right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return func(0,0,m-1,n-1,dp);
    }
};
