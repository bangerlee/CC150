class MyQueue {
private:
    stack<int> stacks;
    stack<int> stackq;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while(!stacks.empty()){
            stacks.pop();
        }
        while(!stackq.empty()){
            int res=stackq.top();
            stacks.push(res);
            stackq.pop();
        }
        stacks.push(x);
        while(!stacks.empty()){
            int res=stacks.top();
            stackq.push(res);
            stacks.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int res=stackq.top();
        stackq.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        return stackq.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stackq.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
