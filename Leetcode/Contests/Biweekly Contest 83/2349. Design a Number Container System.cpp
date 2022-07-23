// Problem Link - https://leetcode.com/contest/biweekly-contest-83/problems/design-a-number-container-system/

#define ll long long

class NumberContainers {
public:
    map<ll,set<ll>> m2;
    map<ll,ll> m1;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
       if(m1.count(index) and m1[index]!=number)
       {
           m2[m1[index]].erase(index);
           if(m2[m1[index]].size()==0)
               m2.erase(m1[index]);
           m2[number].insert(index);
           m1[index] = number;
       }
        else
        {
           m2[number].insert(index);
           m1[index] = number;
        }
    }
    
    int find(int number) {
        if(m2.count(number)==0)
            return -1;
        return *m2[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */