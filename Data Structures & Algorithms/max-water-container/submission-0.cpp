class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0;
        int r=heights.size()-1;
        int maxarea=0;
        while(l<r){
            int w=r-l;
            int area=w*min(heights[l],heights[r]);
            maxarea=max(maxarea,area);
            if(heights[l]>heights[r]){
                r--;
            }
            else{
                l++;
            }
        }
        return maxarea;
    }
};
