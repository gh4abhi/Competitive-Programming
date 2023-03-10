// Problem Link - https://leetcode.com/problems/maximize-distance-to-closest-person/

#define ll int

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
    ll maxD = 0;
    ll ind = 0;
    ll flag = 0; 
        ll start =0,end = 0;
    for(ll i = 0; i<seats.size();i++)
    {
        if(seats[i]==1 and flag)
        {
            maxD = max(maxD, i-ind+1);
            ind = i;
        }
        if(seats[i]==1 and flag == 0)
        {
            ind = i;
            start = i;
            flag = 1;
        }
    }
        for(ll i=seats.size()-1;i>=0;i--)
        {
            if(seats[i]==1)
            {
                    end = seats.size()-i-1;
                    break;
            }
        }
        if(maxD%2==0)
            maxD--;
        return (max(start,max(end,maxD/2)));
    }
};
