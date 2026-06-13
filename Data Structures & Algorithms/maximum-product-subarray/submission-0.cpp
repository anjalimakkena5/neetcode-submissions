class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int left=1;
        int right=1;
        int maxi=-1e9;
        int n=nums.size();
        for(int i=0;i<n;i++){
            left=left==0?1:left;
            right=right==0?1:right;
            left*=nums[i];
            right*=nums[n-i-1];
            maxi=max(maxi,max(left,right));
        }
        return maxi;
        
    }
};
