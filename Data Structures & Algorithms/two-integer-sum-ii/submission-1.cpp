class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int left=1;
        int right=n;
        while(left<right){
            int sum=numbers[left-1]+numbers[right-1];
            if(sum==target){
                return {left,right};
            }
            else if(sum>target){
                right--;
            }
            else{
                left++;
            }
        }
        return {-1};
    }
};
