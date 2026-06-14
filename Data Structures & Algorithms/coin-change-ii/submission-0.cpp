class Solution {
public:
    int func(int ind,int amount,vector<int>&coins,vector<vector<int>>&dp){
        int n=coins.size();
        if(amount==0) return 1;
        if(ind>=n) return 0;
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int take=0;
        if(coins[ind]<=amount){
            take=func(ind,amount-coins[ind],coins,dp);
        }
        int nottake=func(ind+1,amount,coins,dp);
        return dp[ind][amount]=take+nottake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return func(0,amount,coins,dp);
    }
};
