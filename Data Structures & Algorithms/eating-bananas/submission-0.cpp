class Solution {
public:
    int func(int hourly,vector<int>& piles, int h){
        int total=0;
        for(int i=0;i<piles.size();i++){
            total+=ceil((double)piles[i]/(double)hourly);
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=-1;
        while(low<=high){
            int mid=(low+high)>>1;
            int hours=func(mid,piles,h);
            if(hours<=h){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};
