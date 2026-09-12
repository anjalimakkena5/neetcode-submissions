class Solution {
public:
   void solve(int i,vector<int>&leftcol,vector<int>&upperdiag,vector<int>&lowerdiag,int n,vector<string>&board,vector<vector<string>>&ans){
    if(i==n){
        ans.push_back(board);
        return;
    }
    for(int j=0;j<n;j++){
        if(leftcol[j]==0 && lowerdiag[i+j]==0 && upperdiag[n-1+j-i]==0){
            board[i][j]='Q';
            leftcol[j]=1;
            lowerdiag[i+j]=1;
            upperdiag[n-1+j-i]=1;
            solve(i+1,leftcol,upperdiag,lowerdiag,n,board,ans);
            board[i][j]='.';
            leftcol[j]=0;
            lowerdiag[i+j]=0;
            upperdiag[n-1+j-i]=0;
        }
    }
   }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n,string(n,'.'));
        vector<int>leftcol(n,0),upperdiag(2*n-1,0),lowerdiag(2*n-1,0);
        solve(0,leftcol,upperdiag,lowerdiag,n,board,ans);
        return ans;

    }
};
