class Node{
    public:
    Node* link[26];
    bool flag=false;
    void put(char ch,Node* node){
        link[ch-'a']=node;
    }
    Node* get(char ch){
        return link[ch-'a'];
    }
    void setEnd(){
        flag=true;
    }
    bool containskey(char ch){
        return link[ch-'a'];
    }
};
class WordDictionary {
    private:
    Node* root;
public:
    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containskey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
               
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node=root;
        return dfs(word,0,root);
        
    }
    private:
    bool dfs(string &word,int i, Node* root){
        for(int j=i;j<word.size();j++){
            char ch=word[j];
            if(ch=='.'){
                for(int i=0;i<26;i++){
                    if(root->link[i]!=NULL && dfs(word,j+1,root->link[i])){
                        return true;
                    }
                }
                return false;
            }
            else{
                if(!root->containskey(ch)){
                    return false;
                }
                root=root->get(word[j]);
            }
        }
        return root->flag;
    }
};
