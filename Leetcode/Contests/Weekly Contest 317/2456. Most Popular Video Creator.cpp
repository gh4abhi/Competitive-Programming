// Problem Link - https://leetcode.com/contest/weekly-contest-317/problems/most-popular-video-creator/

#define ll long long

class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        unordered_map<string,ll> op;
        unordered_map<string,string> ok;
        unordered_map<string,ll> m;
        ll maxi = INT_MIN;
        for(ll i=0;i<creators.size();i++)
        {
            if(m.count(creators[i])==0)
                m[creators[i]] = -1;
            op[creators[i]] = (op[creators[i]] + views[i]);
            if(views[i]>m[creators[i]])
                ok[creators[i]] = ids[i], m[creators[i]] = views[i];
            else if(views[i]==m[creators[i]] and ids[i]<ok[creators[i]])
                ok[creators[i]] = ids[i];
            maxi = max(maxi,op[creators[i]]);
        }
        vector<vector<string>> ans;
        for(auto i:op)
        {
            if(i.second==maxi)
                ans.push_back({i.first,ok[i.first]});
        }
        return ans;
    }
};