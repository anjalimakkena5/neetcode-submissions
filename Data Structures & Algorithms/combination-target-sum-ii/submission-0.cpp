class Solution {
public:
    void func(int i,int target,vector<int>&nums,vector<int>&curr,vector<vector<int>>&ans){
        int n=nums.size();
        if(target==0){
            ans.push_back(curr);
            return;
        }
        if(i>=n) return;
        for(int j=i;j<n;j++){
            if(j>i && nums[j]==nums[j-1]) continue;
            if(nums[j]>target) break;
            curr.push_back(nums[j]);
            func(j+1,target-nums[j],nums,curr,ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>curr;
        sort(candidates.begin(),candidates.end());
        func(0,target,candidates,curr,ans);
        return ans;
    }
};
