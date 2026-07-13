class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>result;
        deque<int>dq;
        for(int i=0;i<n;i++){
            //step1: make space for new element by deleting out of window elements
            while(!dq.empty() && dq.front()<=i-k) dq.pop_front();
            //step2: when new elements comes delete the ones less than that element
            while(!dq.empty() && nums[dq.back()]<=nums[i])
                 dq.pop_back();
            //step3:add into deque
            dq.push_back(i);
            //step4:add into result
            if(i>=k-1){
                result.push_back(nums[dq.front()]);
           
            }
        }
        return result;
    }
};
