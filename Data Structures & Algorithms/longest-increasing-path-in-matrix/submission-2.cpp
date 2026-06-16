class Solution {
public:
    int func(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&dp){
        int maxi=1;
        int n=matrix.size();
        int m=matrix[0].size();
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        if(dp[i][j]!=-1) return dp[i][j];
        for(int k=0;k<4;k++){
            int nrow=i+dr[k];
            int ncol=j+dc[k];
            if(nrow>=0 && ncol>=0 && nrow<n &&ncol<m && matrix[nrow][ncol]>matrix[i][j]){
                maxi=max(maxi,1+func(nrow,ncol,matrix,dp));
            }
        }
        return dp[i][j]=maxi;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxi=1;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxi=max(maxi,func(i,j,matrix,dp));
            }
        }
        return maxi;
        
    }
};
