class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>mpp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        auto& values=mpp[key];
        int l=0,r=values.size()-1;
        string result="";
        while(l<=r){
            int mid=(l+r)>>1;
            if(values[mid].first<=timestamp){
                result=values[mid].second;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return result;
        
    }
};
