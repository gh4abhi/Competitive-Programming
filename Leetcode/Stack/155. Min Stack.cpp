// Problem Link - https://leetcode.com/problems/min-stack/

#define ll long long

class MinStack {
 ll mini;
 stack<ll> st;   
public:
    MinStack() {
        while(st.size())
            st.pop();
        mini = 1e18;
    }
    
    void push(int val) {
        if(st.size()==0)
            st.push(val), mini = val;
        else
        {
            if(val<mini)
                st.push(2ll*val-mini), mini = val;
            else
                st.push(val);
        }
    }
    
    void pop() {
        if(st.size()==0)
            return;
        if(st.top()<mini)
            mini = 2ll*mini - st.top(),st.pop();
        else
            st.pop();
    }
    
    int top() {
        if(st.top()<mini)
            return mini;
        else
            return st.top();
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */