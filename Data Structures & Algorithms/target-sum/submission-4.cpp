class Solution {
public:
    int func(int ind,int amount,vector<int>&nums,vector<vector<int>>&dp){
        int n=nums.size();
        if(ind==n) return amount==0?1:0;
        
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int take=0;
        if(nums[ind]<=amount){
            take=func(ind+1,amount-nums[ind],nums,dp);
        }
        int nottake=func(ind+1,amount,nums,dp);
        return dp[ind][amount]=take+nottake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int total=0;
        
        for(auto it:nums){
            total+=it;
        }
        if(total-target<0 || (total-target)%2!=0) return 0;
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>((total-target)/2+1,-1));
        return func(0,(total-target)/2,nums,dp);
        
    }
};
