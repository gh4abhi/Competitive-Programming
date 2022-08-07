// Problem Link - https://leetcode.com/problems/trapping-rain-water/

#define ll int

class Solution {
public:
    int trap(vector<int>& height) {
        ll start = 0, end = height.size()-1;
        ll lmaxi = 0 , rmaxi = 0;
        ll ans = 0;
        while(start<=end)
        {
            if(height[start]<=height[end])
            {
                if(height[start]>=lmaxi)
                    lmaxi = height[start];
                else
                    ans += (lmaxi-height[start]);
                start++;
            }
            else
            {
                if(height[end]>rmaxi)
                    rmaxi = height[end];
                else
                    ans+=(rmaxi-height[end]);
                end--;
            }
        }
        return ans;
    }
};