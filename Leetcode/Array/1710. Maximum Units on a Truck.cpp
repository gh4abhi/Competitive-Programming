// Problem Link - https://leetcode.com/problems/maximum-units-on-a-truck/submissions/

#define ll int

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[](vector<ll>& a, vector<ll>& b){    
                      return a[1]>b[1];
        });
        ll ans = 0;
        for(auto i:boxTypes)
        {
            if(truckSize)
                ans += min(truckSize,i[0])*i[1], truckSize -= min(truckSize,i[0]); 
            else
                break;
        }
        return ans;
    }
};