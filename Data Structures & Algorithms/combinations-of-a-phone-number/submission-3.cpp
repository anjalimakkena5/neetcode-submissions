class Solution {
public:
    void func(int i,string digits,unordered_map<char,string>&mpp,string &path,vector<string>&ans){
        if(i==digits.size()) {
            ans.push_back(path);
            return;
        }
        string str=mpp[digits[i]];
        for(int j=0;j<str.size();j++){
            path.push_back(str[j]);
            func(i+1,digits,mpp,path,ans);
            path.pop_back();
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
        int i=0;
        string path="";
        func(i,digits,mpp,path,ans);
        return ans;
    }
};
