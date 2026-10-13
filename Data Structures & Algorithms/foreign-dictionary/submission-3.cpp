class Solution {
public:
    vector<int> toposort(vector<int>adj[],int k){
        int n=k;
        vector<int>indegree(n,0);
        queue<int>q;
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty()){
            int top=q.front();
            q.pop();
            topo.push_back(top);
            for(auto it:adj[top]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        return topo;
    }
    string foreignDictionary(vector<string>& words) {
        vector<int>present(26,0);
        vector<int>adj[26];
        for(auto word:words){
            for(auto ch:word){
                present[ch-'a']=1;
            }
        }
        int n=words.size();
        for(int i=0;i<n-1;i++){
            string s1=words[i];
            string s2=words[i+1];
            int len=min(s1.size(),s2.size());
            int j=0;
            for(j=0;j<len;j++){
                if(s1[j]!=s2[j]){
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
            if(j==len && s1.size()>s2.size()) return "";
        }
        vector<int>topo=toposort(adj,26);
        if(topo.size()!=26) return "";
        string ans="";
        for(auto it:topo){
            if(present[it]){
                ans+=char(it+'a');
            }
        }
        return ans;
        
    }
};
