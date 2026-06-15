class Solution {
public:
    void solve(int i,string &digits,string &curr,vector<string>&ans,unordered_map<char,string>&mpp){
        int n=digits.size();
        if(i==n){
            ans.push_back(curr);
            return;
        }
        char ch=digits[i];
        string str=mpp[ch];
        for(int j=0;j<str.size();j++){
            curr.push_back(str[j]);
            solve(i+1,digits,curr,ans,mpp);
            curr.pop_back();
            
        }
    }
    vector<string> letterCombinations(string digits) {
         vector<string>ans;
        if(digits.size()==0) return ans;
        unordered_map<char,string>mpp;
        mpp['2']="abc";
        mpp['3']="def";
        mpp['4']="ghi";
        mpp['5']="jkl";
        mpp['6']="mno";
        mpp['7']="pqrs";
        mpp['8']="tuv";
        mpp['9']="wxyz";
       
        string curr;
        solve(0,digits,curr,ans,mpp);
        return ans;
        
    }
};
