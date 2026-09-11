class Solution {
public:
    void func(int i,vector<int>&nums,vector<int>&path,vector<vector<int>>&ans){
        int n=nums.size();
        if(i==n){
            ans.push_back(path);
            return;
        }
        path.push_back(nums[i]);
        func(i+1,nums,path,ans);
        path.pop_back();
        func(i+1,nums,path,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        int i=0;
        vector<int>path;
        func(i,nums,path,ans);
        return ans;
        
    }
};
