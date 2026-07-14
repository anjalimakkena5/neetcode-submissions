class Solution {
public:
    void nextsmaller(vector<int>& heights,vector<int>&nsr){
        int n=heights.size();
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            nsr[i]=st.empty()?n:st.top();
            st.push(i);
        }
    }
    void prevsmaller(vector<int>& heights,vector<int>&psl){
        int n=heights.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            psl[i]=st.empty()?-1:st.top();
            st.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>nsr(n,n);
        vector<int>psl(n,-1);
        nextsmaller(heights,nsr);
        prevsmaller(heights,psl);
        int maxi=0;
        for(int i=0;i<n;i++){
            int width=nsr[i]-psl[i]-1;
            int area=width*heights[i];
            maxi=max(maxi,area);
        }
        return maxi;
    }
};
