class Solution {
public:
    bool ispalindrome(int l,int r,string &s){
        if(l>r) return false;
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n=s.size();
        int start=0;
        int maxlen=1;
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                
                if(ispalindrome(i,j,s)){
                    int len=j-i+1;
                    if(len>maxlen){
                        maxlen=len;
                        start=i;
                    }
                    
                }
            }
        }
       return  s.substr(start,maxlen);
    }
};
