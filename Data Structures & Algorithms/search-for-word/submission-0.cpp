class Solution {
public:
    bool solve(int ind,int i,int j,vector<vector<char>>&board,string &word){
        int n=board.size();
        int m=board[0].size();
        if(ind==word.size()){
            return true;
        }
        if(i<0||i>=n||j<0||j>=m||board[i][j]=='#'||board[i][j]!=word[ind]){
            return false;
        }
        char temp=board[i][j];
        board[i][j]='#';
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        for(int k=0;k<4;k++){
            int nrow=i+dr[k];
            int ncol=j+dc[k];
            if(solve(ind+1,nrow,ncol,board,word)) return true;
        }
        board[i][j]=temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(word[0]==board[i][j] && solve(0,i,j,board,word)) return true;
    
            }
        }
        return false;
        
    }
};
