class Solution {
public:
    bool possible(vector<vector<int>>&grid,int i,int j,int mid,vector<vector<int>>&vis){
        int n=grid.size();
        if(i<0 ||j<0 ||i>=n ||j>=n ||grid[i][j]>mid ||vis[i][j]==1) return false;
        if(i==n-1 && j==n-1) return true;
        vis[i][j]=1;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        for(int k=0;k<4;k++){
            int nrow=i+dr[k];
            int ncol=j+dc[k];
            if(possible(grid,nrow,ncol,mid,vis)) return true;
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int l=grid[0][0];
        int r=n*n-1;
        int result=0;
        while(l<=r){
            int mid=(l+r)>>1;
            vector<vector<int>>vis(n,vector<int>(n,0));
            if(possible(grid,0,0,mid,vis)){
                result=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return result;
    }
};
