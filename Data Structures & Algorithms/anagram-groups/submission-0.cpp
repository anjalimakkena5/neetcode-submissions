class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>result;
        unordered_map<string,vector<string>>mpp;
        for(auto num:strs){
            string temp=num;
            sort(temp.begin(),temp.end());
            mpp[temp].push_back(num); 
        }
        for(auto it:mpp){
            result.push_back(it.second);
        }
        return result;
    }
};
