class Solution {
public:
    bool isvalid(int i,int j,char digit,vector<vector<char>>&board){
        int n=board.size();
        int m=board[0].size();
        for(int k=0;k<m;k++){
            if(k!=j && board[i][k]==digit) return false;
            if(k!=i && board[k][j]==digit) return false;
        }
        int sr=i/3*3;
        int sc=j/3*3;
        for(int p=0;p<3;p++){
            for(int q=0;q<3;q++){
                if(board[sr+p][sc+q]==digit) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    char ch=board[i][j];
                    board[i][j]='.';
                    if(!isvalid(i,j,ch,board)) return false;
                    board[i][j]=ch;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        return solve(board);
    }
};
