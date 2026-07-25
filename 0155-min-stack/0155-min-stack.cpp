class MinStack {
    multiset<int> minimum;
    stack<int> st;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        minimum.insert(value);
        st.push(value);
    }
    
    void pop() {
        if(st.empty()) return;
        auto it = minimum.find(st.top());
        if (it != minimum.end())
            minimum.erase(it);
        st.pop();
    }
    
    
    int top() {
        if(st.empty()) return -1;
        return st.top();
    }
    
    int getMin() {
        if(st.empty()) return -1;
        return *minimum.begin();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */