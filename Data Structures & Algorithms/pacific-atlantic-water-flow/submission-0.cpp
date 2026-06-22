class Solution {
public:
    void bfs(queue<pair<int,int>>&q,vector<vector<int>>&vis,vector<vector<int>>&heights){
        int n=heights.size();
        int m=heights[0].size();
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            vis[row][col]=1;
            int dr[]={-1,0,1,0};
            int dc[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && heights[nrow][ncol]>=heights[row][col]){
                    q.push({nrow,ncol});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        queue<pair<int,int>>pq;
        queue<pair<int,int>>aq;
        vector<vector<int>>pq_vis(n,vector<int>(m,0));
        vector<vector<int>>aq_vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            pq.push({i,0});
            aq.push({i,m-1});
        }
        for(int j=0;j<m;j++){
            pq.push({0,j});
            aq.push({n-1,j});
        }
        bfs(pq,pq_vis,heights);
        bfs(aq,aq_vis,heights);
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pq_vis[i][j] &&aq_vis[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;

        
    }
};
