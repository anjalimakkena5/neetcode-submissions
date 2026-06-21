class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>>q;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                };
            }
        }
        while(!q.empty()){
           int steps= q.front().first;
           int row=q.front().second.first;
           int col=q.front().second.second;
           q.pop();
           grid[row][col]=steps;
           int dr[]={-1,0,1,0};
           int dc[]={0,1,0,-1};
           for(int i=0;i<4;i++){
               int nrow=row+dr[i];
               int ncol=col+dc[i];
               if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==2147483647 && vis[nrow][ncol]==0){
                   vis[nrow][ncol]=1;
                   q.push({steps+1,{nrow,ncol}});
               }
           }
        }
    }
};
