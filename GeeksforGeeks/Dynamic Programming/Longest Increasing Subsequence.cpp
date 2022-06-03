// Problem Link - https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1#

#define ll int

class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       ll ans = 1;
       vector<ll> vect;
       vect.push_back(a[0]);
       for(ll i=1;i<n;i++)
       {
           if(a[i]>vect.back())
            vect.push_back(a[i]), ans++;
            else
            {
                ll ind = lower_bound(vect.begin(),vect.end(),a[i]) - vect.begin();
                vect[ind] = a[i];
            }
       }
       return ans;
    }
};
