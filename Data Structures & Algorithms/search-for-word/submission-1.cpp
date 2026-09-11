class Solution {
public:
    bool func(int row,int col,int ind,vector<vector<int>>&vis,vector<vector<char>>& board, string word){
        int n=board.size();
        int m=board[0].size();
        vis[row][col]=1;
        if(ind==word.size()-1) return true;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=row+dr[i];
            int ncol=col+dc[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]==word[ind+1] && !vis[nrow][ncol]){
                if(func(nrow,ncol,ind+1,vis,board,word)) return true;
            }
        }
        vis[row][col]=0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(func(i,j,0,vis,board,word)) return true;
                }
            }
        }
        return false;
        
    }
};
