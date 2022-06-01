// Problem Link - https://leetcode.com/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period/

#define ll long long

class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        map<string,vector<string>> m;
        for(ll i=0;i<keyName.size();i++)
            m[keyName[i]].push_back(keyTime[i]);
        vector<string> ans;
        for(auto i:m)
        {
            if(i.second.size()<3)
                continue;
            sort(i.second.begin(),i.second.end());
            for(ll j = 0;j<i.second.size()-2;j++)
            {
                ll count = 1;
                ll a = stoll(i.second[j].substr(0,2));
                ll b = stoll(i.second[j+1].substr(0,2));
                ll c = stoll(i.second[j].substr(3,2));
                ll d = stoll(i.second[j+1].substr(3,2));
                if(a==b)
                    count+=1;
                else if(b-a==1 and d-c<=0)
                    count+=1;
                ll e = stoll(i.second[j+2].substr(0,2));
                ll f = stoll(i.second[j+2].substr(3,2));
                if(e==a)
                    count+=1;
                else if(e-a==1 and f-c<=0)
                    count+=1;
                if(count==3)
                {
                    cout<<i.second[j]<<" "<<i.second[j+1]<<" "<<i.second[j+2];
                    ans.push_back(i.first);
                    break;
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};