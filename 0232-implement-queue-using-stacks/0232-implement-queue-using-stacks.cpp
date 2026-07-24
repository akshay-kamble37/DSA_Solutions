class MyQueue {
    stack<int> one;
    stack<int> two;
    int front;
public:
    MyQueue() {
        front = 0;
    }
    
    void push(int x) {
        one.push(x);
    }
    
    int pop() {
        if(!two.empty()){
            int ans = two.top();
            two.pop();
            return ans;
        }else if( one.empty()){
            return -1;
        }

        while( ! one.empty()){
            two.push(one.top());
            one.pop();
        }
        int ans=two.top();
        two.pop();
        return ans;
    }
    
    int peek() {
        if( ! two.empty()){
            return two.top();
        }else if( one.empty()){
            return -1;
        }
        while(! one.empty()){
            two.push(one.top());
            one.pop();
        }
        return two.top();
        
    }
    
    bool empty() {
        if(two.empty() && one.empty()) return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */