class MyStack {
private:
    queue<int> q1 , q2;
    
public:
    MyStack() {
        
    }
    
    void push(int x) {
        
        // push fresh ele to q2
        // push all the remaining ele in q1 to q2
        // swap q1 and q2
        
        q2.push(x);
        
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }
    
    int pop() {
        int temp = q1.front();
        q1.pop();
        
        return temp;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.size() == 0 ? 1 : 0;
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