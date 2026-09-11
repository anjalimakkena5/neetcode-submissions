class Solution {
public:
    void func(int i,vector<int>&nums,int target,vector<int>&path,vector<vector<int>>&ans){
        int n=nums.size();
        if(i>=n ||target<0) return;
        if(target==0){
            ans.push_back(path);
            return;
        }
        path.push_back(nums[i]);
        func(i,nums,target-nums[i],path,ans);
        path.pop_back();
        func(i+1,nums,target,path,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>path;
        int i=0;
        func(i,nums,target,path,ans);
        return ans;
    }
};
