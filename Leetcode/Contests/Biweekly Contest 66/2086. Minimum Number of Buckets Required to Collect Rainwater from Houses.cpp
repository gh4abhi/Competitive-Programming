// Problem Link - https://leetcode.com/problems/minimum-number-of-buckets-required-to-collect-rainwater-from-houses/

#define ll int
using namespace std;

class Solution {
public:
    int minimumBuckets(string str) {
        ll n = str.length();
        if(n==1)
        {
            if(str[0]=='.')
                return 0;
            else
                return -1;
        }
        if(n==2)
        {
            if(str[0]=='H' and str[1]=='H')
                return -1;
             else if(str[0]=='.' and str[1]=='.')
                 return 0;
             else 
                 return 1;
        }
        ll count = 0;
        for(ll i=0;i<n-2;i++)
        {
            if(i==0)
            {
                if(str[i]=='H')
                {
                    if(str[i+1]=='.' and str[i+2]=='H')
                    {
                        str[i+1] = 'B';
                        count++;
                    }
                }
            }
            else if(str[i]=='H')
            {
                if(str[i-1]=='B' or str[i+1]=='B')
                    continue;
                if(str[i+1]=='.' and str[i+2]=='H')
                {
                    str[i+1] = 'B';
                    count++;
                }
            }
        }
        cout<<str<<"\n";
        for(ll i=0;i<n;i++)
        {
            if(i==0)
            {
                if(str[i]=='H')
                {
                    if(str[i+1]=='.')
                    {
                        str[i+1] = 'B';
                        count++;
                    }
                    else if(str[i+1]=='B')
                    {
                        continue;
                    }
                    else
                    {
                        return -1;
                    }
                }
            }
            else if(i==n-1)
            {
                if(str[i]=='H')
                {
                    if(str[i-1]=='.')
                    {
                        str[i-1] = 'B';
                        count++;
                    }
                    else if(str[i-1]=='B')
                        continue;
                    else 
                        return -1;
                }
            }
            
            else if(str[i]=='H')
            {
                if(str[i-1]=='B' or str[i+1]=='B')
                    continue;
                else if(str[i+1]=='.')
                {
                    str[i+1] = 'B';
                    count++;
                }
                else if(str[i-1]=='.')
                {
                    str[i-1] = 'B';
                    count++;
                }
                else
                {
                    return -1;
                }
                     
            }
        }
                cout<<str;
        return count;
    }
};
