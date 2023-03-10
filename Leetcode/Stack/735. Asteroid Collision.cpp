// Problem Link - https://leetcode.com/problems/asteroid-collision/

#define ll int

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<ll> st;
        for(auto i:asteroids)
        {
            if(st.size()==0)
            {
                st.push(i);
                continue;
            }
            if(st.top()>0 and i<0)
            {
                ll flag = 1;
                while(st.size() and st.top()>0 and st.top()<=abs(i))
                {
                    if(st.top()==abs(i))
                    {
                        flag = 0;
                        st.pop();
                        break;
                    }
                    st.pop();
                }
                if((st.size()==0 or st.top()<0) and flag)
                    st.push(i);
            }
            else
                st.push(i);
        }
        vector<ll> vect;
        while(st.size())
            vect.push_back(st.top()), st.pop();
        reverse(vect.begin(),vect.end());
        return vect;
    }
};