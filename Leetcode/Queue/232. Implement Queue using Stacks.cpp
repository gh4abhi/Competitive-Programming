// Problem Link - https://leetcode.com/problems/implement-queue-using-stacks/

#define ll int
class MyQueue {
    private:
        stack<ll> input;
        stack<ll> output;
        ll sz;
public:
    MyQueue() {
        sz = 0;
    }
    
    void push(int x) {
          input.push(x);
            sz++;
    }
    
    int pop() {
              if(output.size())
            {
                ll cur = output.top();
                output.pop();
                sz--;
                return cur;
            }
            else if(input.size())
            {
                while(input.size())
                    output.push(input.top()),input.pop();
                ll cur = output.top();
                output.pop();
                sz--;
                return cur;
            }
            else
                return -1;
    }
    
    int peek() {
               if(output.size())
            {
                ll cur = output.top();
                return cur;
            }
            else if(input.size())
            {
                   while(input.size())
                    output.push(input.top()),input.pop();
                ll cur = output.top();
                return cur;
            }
            else
                return -1;   
    }
    
    bool empty() {
        return sz ==0;
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