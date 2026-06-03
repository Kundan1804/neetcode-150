class MinStack {
private:
    stack<int> minStack; 
    stack<int> mainStack; 
public:
    MinStack() {
        minStack.push(INT_MAX);
    }
    
    void push(int val) {
        mainStack.push(val);
        if(minStack.empty() || val <= minStack.top()){
            minStack.push(val);
        }
    }
    
    void pop() {
        if(!mainStack.empty()){
            int topVal = mainStack.top();
            mainStack.pop();
            if(minStack.top()==topVal){
                minStack.pop();
            }
        }
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
