class Solution {
public:
    string generate(string &word){
        int cnt[26]={0};
        for(auto it:word){
            cnt[it-'a']++;
        }
            string newword="";
            for(int i=0;i<26;i++){
                int freq=cnt[i];
                newword+=string(freq,i+'a');
            }
            
        return newword;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>result;
        unordered_map<string,vector<string>>mpp;
        for(auto num:strs){
            string newword=generate(num);
            mpp[newword].push_back(num); 
        }
        for(auto it:mpp){
            result.push_back(it.second);
        }
        return result;
    }
};
