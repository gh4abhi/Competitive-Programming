// Problem Link - https://leetcode.com/problems/find-original-array-from-doubled-array/

#define ll int

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<ll> ans;
        map<ll,ll> m;
        vector<ll> temp;
        sort(changed.begin(),changed.end());
        for(ll i=0;i<changed.size();i++)
        {
            m[changed[i]]++;
        }
        
        for(ll i=0;i<changed.size();i++)
        {
            if(m[changed[i]])
            {
                m[changed[i]]--;
                if(m[changed[i]*2]==0)
                    return temp;
                m[2*changed[i]]--;
                ans.push_back(changed[i]);
            }
        }
        return ans;
    }
};