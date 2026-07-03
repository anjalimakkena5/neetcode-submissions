class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<int>hash(256,0);
        for(int  i=0;i<m;i++){
            hash[t[i]]++;
        }
        int l=0,r=0,cnt=0,minl=1e9,start=-1;
        while(r<n){
            if(hash[s[r]]>0){
                cnt=cnt+1;
            }
            hash[s[r]]--;
            while(cnt==m){
                if(r-l+1<minl){
                    minl=r-l+1;
                    start=l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0){
                    cnt=cnt-1;
                }
                l++;
            }
            r++;
        }
        return start==-1?"":s.substr(start,minl);
    }
};
