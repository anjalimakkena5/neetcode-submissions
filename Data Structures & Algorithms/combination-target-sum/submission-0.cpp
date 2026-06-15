class Solution {
public:
    void func(int i,int target,vector<int>&nums,vector<int>&curr,vector<vector<int>>&ans){
        int n=nums.size();
        if(target==0){
            ans.push_back(curr);
            return;
        }
        if(i>=n) return;
        if(nums[i]<=target){
            curr.push_back(nums[i]);
            func(i,target-nums[i],nums,curr,ans);
            curr.pop_back();
        }
        func(i+1,target,nums,curr,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>curr;
        func(0,target,nums,curr,ans);
        return ans;
        
    }
};
