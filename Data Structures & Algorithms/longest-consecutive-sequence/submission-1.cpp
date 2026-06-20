class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxlength=1;
        unordered_set<int>st;
        int n=nums.size();
        if(n==0) return 0;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        for(auto num:nums){
            if(st.find(num-1)==st.end()){
                int length=1;
                while(st.find(num+1)!=st.end()){
                    num=num+1;
                    length=length+1;
                }
                maxlength=max(maxlength,length);
            }
           
        }
        return maxlength;
    }
};
