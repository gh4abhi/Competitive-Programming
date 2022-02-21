// Problem Link - https://leetcode.com/problems/employee-importance/

#define ll int

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    
    ll sum = 0;
    map<ll,Employee*> m;
    void DFS(Employee* emp)
    {
        sum += emp->importance;
        if(emp->subordinates.size()==0)
        {
            return;
        }
        for(auto j:emp->subordinates)
        {
            DFS(m[j]);
        }
    }
    
    int getImportance(vector<Employee*> employees, int id) {
       for(auto i:employees)
           m[i->id] = i;
        for(auto i:employees)
        {
            if(i->id==id)
            {
                DFS(i);
                break;
            }
        }
        return sum;
    }
};