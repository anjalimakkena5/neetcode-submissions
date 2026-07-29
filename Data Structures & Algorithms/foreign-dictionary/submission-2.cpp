class Solution {
public:
    vector<int> toposort(unordered_set<int>adj[26],int n){
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        return topo;
    }
    string foreignDictionary(vector<string>& words) {
        vector<bool> present(26, false);

for (auto &word : words)
    for (char c : word)
        present[c-'a'] = true;
        queue<int>q;
        int k=26;
        unordered_set<int>adj[26];
        int n=words.size();
        for(int i=0;i<n-1;i++){
            string s1=words[i];
            string s2=words[i+1];
            int len=min(s1.size(),s2.size());
            for(int j=0;j<len;j++){
                if(s1[j]!=s2[j]){
                    adj[s1[j]-'a'].insert(s2[j]-'a');
                    break;
                }
                if(j==len-1 && s1.size()>s2.size()) return "";
            }
        }
        
        vector<int>topo=toposort(adj,k);
        if(topo.size()!=26) return "";
        string ans="";
        for(auto it:topo){
            if(present[it])
            ans+=char(it+'a');
        }
        return ans;
    }
};
