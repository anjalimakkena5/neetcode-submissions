class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mpp;
        int n=s.size();
        for(int i=0;i<n;i++){
            mpp[s[i]]=i;
        }
        int prev=-1;
        int maxi=0;
        
        vector<int>ans;
        for(int i=0;i<n;i++){
            maxi=max(maxi,mpp[s[i]]);
            if(maxi==i){
                ans.push_back(maxi-prev);
                prev=maxi;
            }
        }
        return ans;

    }
};
