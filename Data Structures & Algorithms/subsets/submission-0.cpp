class Solution {
public:
    void func(int i,vector<int>&nums,vector<int>&curr,vector<vector<int>>&ans){
        int n=nums.size();
        if(i==n){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        func(i+1,nums,curr,ans);
        curr.pop_back();
        func(i+1,nums,curr,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
        func(0,nums,curr,ans);
        return ans;
        
    }
};
