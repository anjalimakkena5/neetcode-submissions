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
        vector<int>temp1;
        vector<int>temp2;
        int n=nums.size();
        if(n==1) return nums[0];
        for(int i=0;i<nums.size();i++){
            if(i!=0){
                temp2.push_back(nums[i]);
            }
            if(i!=n-1){
                temp1.push_back(nums[i]);
            }
        }
        vector<int>dp1(n+1,-1);
        vector<int>dp2(n+1,-1);
        return max(func(0,temp1,dp1),func(0,temp2,dp2));
        
    }
};
