class Solution {
public:
    void func(int i,vector<int>&nums,vector<int>&curr,vector<vector<int>>&ans,vector<int>&vis){
        int n=nums.size();
        if(curr.size()==n){
            ans.push_back(curr);
            return;
        }
        for(int j=0;j<n;j++){
            if(!vis[j]){
                curr.push_back(nums[j]);
                vis[j]=1;
                func(j+1,nums,curr,ans,vis);
                vis[j]=0;
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>curr;
        vector<int>vis(n,0);
        func(0,nums,curr,ans,vis);
        return ans;
    }
};
