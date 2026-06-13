class Solution {
public:
    bool func(int ind,int target,vector<int>&nums,vector<vector<int>>&dp){
        int n=nums.size();
        if(target==0) return true;
        if(ind>=n) return false;
        if(dp[ind][target]!=-1) return dp[ind][target];
        bool take=0;
        if(nums[ind]<=target){
            take=func(ind+1,target-nums[ind],nums,dp);
        }
        bool nottake=func(ind+1,target,nums,dp);
        return dp[ind][target]=take||nottake;
    }
    bool canPartition(vector<int>& nums) {
        int total=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            total+=nums[i];
        }
        if(total%2!=0) return false;
        vector<vector<int>>dp(n+1,vector<int>(total/2+1,-1));
        return func(0,total/2,nums,dp);
    }
};
