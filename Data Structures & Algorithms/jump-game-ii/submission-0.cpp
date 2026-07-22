class Solution {
public:
    int jump(vector<int>& nums) {
        int farthest=0,n=nums.size(),jumps=0,curr=0;
        for(int i=0;i<n-1;i++){
            farthest=max(farthest,i+nums[i]);
            if(curr==i){
                jumps++;
                curr=farthest;
            }
        }
        return jumps;
    }
};
