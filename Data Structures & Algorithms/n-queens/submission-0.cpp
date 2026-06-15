class Solution {
public:

    void solve(int i,vector<int>&col,vector<int>&lowerdiag,vector<int>&upperdiag,vector<string>&board,vector<vector<string>>&ans,int n){
        if(i==n){
            ans.push_back(board);
            return;
        }
        for(int j=0;j<n;j++){
            if(col[j]==0 && lowerdiag[i+j]==0 && upperdiag[n-1+j-i]==0){
                board[i][j]='Q';
                col[j]=1;
                lowerdiag[i+j]=1;
                upperdiag[n-1+j-i]=1;
                solve(i+1,col,lowerdiag,upperdiag,board,ans,n);
                board[i][j]='.';
                col[j]=0;
                lowerdiag[i+j]=0;
                upperdiag[n-1+j-i]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n,string(n,'.'));
        vector<int>col(n,0),lowerdiag(2*n-1,0),upperdiag(2*n-1,0);
        solve(0,col,lowerdiag,upperdiag,board,ans,n);
        return ans;
    }
};
