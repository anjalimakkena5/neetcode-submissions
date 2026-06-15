class Solution {
public:
    void func(int i,vector<int>&nums,vector<int>&curr,vector<vector<int>>&ans){
        int n=nums.size();
        ans.push_back(curr);
        for(int j=i;j<n;j++){
            if(j>i && nums[j]==nums[j-1]) continue;
            curr.push_back(nums[j]);
            func(j+1,nums,curr,ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
        sort(nums.begin(),nums.end());
        func(0,nums,curr,ans);
        return ans;
        
    }
};
