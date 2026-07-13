class MinStack {
public:
    stack<long long>st;
    long long mini;
    MinStack() {
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            mini=val;
        }
        else{
            if(val>=mini){
                st.push(val);
            }
            else{
                st.push(2ll*val-mini);
                mini=val;
            }
        }
    }
    
    void pop() {
        long long x=st.top();
        st.pop();
        if(x<mini){
            mini=2*mini-x;
        }
    }
    
    int top() {
        long long x=st.top();
        if(x<mini){
            return mini;
        }
        else{
            return x;
        }
    }
    
    int getMin() {
        return mini;
    }
};
