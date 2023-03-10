// Problem Link - https://www.codingninjas.com/codestudio/problems/queue-using-stack_799482?topList=striver-sde-sheet-problems

#include<bits/stdc++.h>
#define ll int

class Queue {
  private:
        stack<ll> input;
        stack<ll> output;
        ll sz;
    public:
    Queue() {
                    sz = 0;

    }

    void enQueue(int x) {
             input.push(x);
            sz++;
    }

    int deQueue() {
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

    bool isEmpty() {
              return sz ==0;

    }
};