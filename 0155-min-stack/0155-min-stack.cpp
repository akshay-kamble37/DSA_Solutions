class MinStack {
    stack<int> one;
    stack<int> two;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        one.push(value);
        if( two.empty() || two.top() >= value){
           two.push(value);
        }
    }
    
    void pop() {
        if(one.empty()) return;
        if(one.top() == two.top()){
            two.pop();
        }
        one.pop();
    }
    
    int top() {
        if(one.empty()) return -1;
        return one.top();
    }
    
    int getMin() {
        if(one.empty()) return -1;
        return two.top();
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