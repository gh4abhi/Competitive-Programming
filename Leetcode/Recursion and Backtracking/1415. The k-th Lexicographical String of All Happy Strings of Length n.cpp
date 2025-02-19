// Problem Link - https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/?envType=daily-question&envId=2025-02-19

#define ll int

class Solution {
public:
    map<string,ll> m;

    void fun(ll ind, string str, ll n)
    {
        if(ind==n)
        {
            m[str]++;
            return;
        }
        if(str.length()==0){
            fun(ind+1,str+string(1,'a'),n);
            fun(ind+1,str+string(1,'b'),n);
            fun(ind+1,str+string(1,'c'),n);
        }
        else{
            if(str[ind-1]!='a')
                fun(ind+1,str+string(1,'a'),n);
            if(str[ind-1]!='b')
                fun(ind+1,str+string(1,'b'),n);
            if(str[ind-1]!='c')
                fun(ind+1,str+string(1,'c'),n);
        }
    }

    string getHappyString(int n, int k) {
        m.clear();
        fun(0,"",n);
        if(m.size()<k)
            return "";
        auto it = m.begin();
        for(ll i=0;i<k-1;i++)
            it++;
        return it->first;
    }
};

