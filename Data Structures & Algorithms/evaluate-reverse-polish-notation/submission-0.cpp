class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/"){
                st.push(stoi(tokens[i]));
            }
            else{
                int y=st.top();
                st.pop();
                int x=st.top();
                st.pop();
                if(tokens[i]=="+"){
                    st.push(x+y);
                }
                else if(tokens[i]=="-"){
                    st.push(x-y);
                }
                else if(tokens[i]=="*"){
                    st.push(x*y);
                }
                else{
                    st.push(x/y);
                }

            }
        }
        return st.top();
        
    }
};
