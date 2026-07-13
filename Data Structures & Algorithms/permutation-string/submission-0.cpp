class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        if(n>m) return false;
        vector<int>freq_s1(26,0);
        vector<int>freq_s2(26,0);
        for(char c:s1){
            freq_s1[c-'a']++;
        }
        int l=0;
        int r=0;
        while(r<m){
            freq_s2[s2[r]-'a']++;
            if(r-l+1>n){
                freq_s2[s2[l]-'a']--;
                l++;
            }
            if(freq_s1==freq_s2) return true;
            r++;
        }
        return false;
    }
};
