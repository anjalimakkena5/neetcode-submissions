class Solution {
public:
    int func(int ind,vector<int>&nums,vector<int>&dp){
        int n=nums.size();
        if(ind>=n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int take=nums[ind]+func(ind+2,nums,dp);
        int nottake=func(ind+1,nums,dp);
        return dp[ind]=max(take,nottake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return func(0,nums,dp);
        
    }
};
