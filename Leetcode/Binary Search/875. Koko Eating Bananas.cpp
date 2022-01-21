// Problem Link - https://leetcode.com/problems/koko-eating-bananas/

#define ll int

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        if(piles.size()==1)
        {
            ll ans = ceil((piles[0]*1.0)/h);
            return ans;
        }
        sort(piles.begin(), piles.end());
        
        ll low = 0;
        ll high = piles[piles.size()-1];
        ll tempAns = high;
        if(h==piles.size())
        {
            return high; 
        }
        while(low<=high)
        {
            ll mid = (low) +(high-low)/2;
            ll val = mid;
            ll time = 0;
            for(ll i=0; i<piles.size();i++)
            {
                time+= ceil((piles[i]*1.0)/val);
            }
            if(time<=h)
            {
                tempAns = min(tempAns,mid);
                high = mid-1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return tempAns;
    }
};
