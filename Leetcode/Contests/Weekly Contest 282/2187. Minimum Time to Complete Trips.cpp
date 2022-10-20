// Problem Link - https://leetcode.com/contest/weekly-contest-282/problems/minimum-time-to-complete-trips/

#define ll long long

class Solution {
public:
    
    bool isPossible(vector<int> &time, ll x , ll total)
    {
        ll count = 0;
        for(auto i:time)
        {
            count = (count + x/(ll)i);
            if(count>=total)
                return true;
        }
        return count>=total;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(),time.end());
        ll start  = 0, end = 1e18;
        ll ans = -1;
        while(start<=end)
        {
            ll mid = start + (end-start)/2;
            if(isPossible(time,mid,totalTrips))
                ans = mid, end = mid-1;
            else
                start = mid+1;
        }
        return ans;
    }
};