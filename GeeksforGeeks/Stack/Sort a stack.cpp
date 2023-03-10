// Problem Link - https://practice.geeksforgeeks.org/problems/sort-a-stack/1

#define ll int
/*The structure of the class is
class SortedStack{
public:
    stack<int> s;
    void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void SortedStack :: sort()
{
    if(s.size()==0)
        return;
    ll cur = s.top();
    s.pop();
    sort();
    stack<ll> temp;
    while(s.size() and cur<s.top())
    {
        temp.push(s.top());
        s.pop();
    }
    s.push(cur);
    while(temp.size())
    {
        s.push(temp.top());
        temp.pop();
    }
}