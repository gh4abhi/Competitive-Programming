// Problem Link - https://leetcode.com/problems/design-a-stack-with-increment-operation/?envType=daily-question&envId=2024-09-30

#define ll int

class CustomStack {
public:

    stack<ll> st1;
    stack<ll> st2;
    ll sz;

    CustomStack(int maxSize) {
        sz = maxSize;
    }
    
    void push(int x) {
        if(st1.size()<sz)
            st1.push(x);
    }
    
    int pop() {
        if(st1.size()==0)
            return -1;
        ll op = st1.top();
        st1.pop();
        return op;
    }
    
    void increment(int k, int val) {
        ll x = max(0,(ll)st1.size()-k);
        ll ind = 0;
        while(st1.size())
        {
            if(ind>=x)
                st2.push(st1.top()+val);
            else
                st2.push(st1.top());
            st1.pop();
            ind++;
        }
        while(st2.size())
            st1.push(st2.top()), st2.pop();
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */