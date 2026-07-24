class MyStack {
    int size;
    queue<int> que; 
public:
    MyStack() {
        size = 0;
    }
    
    void push(int x) {
        que.push(x);
        int copy = size;
        size++;
        while(copy !=0){
            que.push(que.front());
            que.pop();
            copy--;
        }
    }
    
    int pop() {
        if(size == 0) return 0;
        size--;
        int ans = que.front();
        que.pop();
        return ans;
    }
    
    int top() {
        if(size == 0) return 0;
        return que.front();
    }
    
    bool empty() {
        if(size == 0) return true;
        return false; 
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */