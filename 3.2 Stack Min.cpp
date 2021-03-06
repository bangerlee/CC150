class MinStack {
private:
    stack<int> st;
    int min=INT_MAX;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if(x<=min){
            st.push(min);
            min=x;
        }
        st.push(x);
    }
    
    void pop() {
        int tmp=st.top();
        st.pop();
        if(min==tmp){
            min=st.top();
            st.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
