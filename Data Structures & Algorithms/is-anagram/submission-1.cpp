class Solution {
public:
    bool isAnagram(string s, string t) {
       unordered_map<char,int>counts;
       unordered_map<char,int>countt;
       if(s.size()!=t.size()) return false;
       int n=s.size();
       for(int i=0;i<n;i++){
        counts[s[i]]++;
        countt[t[i]]++;
       }
       return counts==countt;
    }
};
