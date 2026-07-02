class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        vector<int>hash(256,-1);
        int l=0,r=0,len=0,maxl=0;
        while(r<n){
            if(hash[s[r]!=-1]){
                l=max(hash[s[r]]+1,l);
            }
            len=r-l+1;
            maxl=max(maxl,len);
            hash[s[r]]=r;
            r++;

        }
        return maxl;
    }
};
