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
    void solve(int i,string &s,vector<string>&curr,vector<vector<string>>&ans){
        int n=s.size();
        if(i==n){
            ans.push_back(curr);
            return;
        }
        for(int j=i;j<n;j++){
            if(ispalindrome(i,j,s)){
                curr.push_back(s.substr(i,j-i+1));
                solve(j+1,s,curr,ans);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>curr;
        solve(0,s,curr,ans);
        return ans;
        
    }
};
