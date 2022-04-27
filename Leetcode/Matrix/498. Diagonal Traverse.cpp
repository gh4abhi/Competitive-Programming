// Problem Link - https://leetcode.com/problems/diagonal-traverse/

#define ll int

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<ll> ans;
        ll flag = 0;
        for(ll i=0;i<mat.size();i++)
        {
            ll j=0;
            ll val = i;
            vector<ll> temp;
            while(val>=0 and j<mat[0].size())
            {
                temp.push_back(mat[val][j]);
                val--;
                j++;
            }
            if(flag)
                reverse(temp.begin(),temp.end());
            ans.insert(ans.end(),temp.begin(),temp.end());
            flag = !flag;
        }
        if(mat[0].size()>1)
        for(ll j=1;j<mat[0].size();j++)
        {
            ll i=mat.size()-1;
            ll val = j;
            vector<ll> temp;
            while(i>=0 and val<mat[0].size())
            {
                temp.push_back(mat[i][val]);
                val++;
                i--;
            }
            if(flag)
                reverse(temp.begin(),temp.end());
            ans.insert(ans.end(),temp.begin(),temp.end());
            flag = !flag;
        }
        return ans;
    }
};