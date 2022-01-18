// Problem Link - https://leetcode.com/problems/can-place-flowers/

#define ll int

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n==0)
            return true;
        if(flowerbed.size()==1)
        {
            if(n==1)
            {
                if(flowerbed[0]==0)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
       ll count = 0;
        vector<ll> flower = flowerbed;
        for(ll i=0;i<flower.size();i++)
        {
            if(flower[i]==0)
            {
                if(i==0)
                {
                   if(flower[i+1]==0)
                   {
                       count++;
                       flower[i] = 1;
                   }
                }
                else if(i==flower.size()-1)
                {
                    if(flower[i-1]==0)
                    {
                        count++;
                        flower[i] = 1;
                    }
                }
                else
                {
                    if(flower[i-1]==flower[i+1] and flower[i+1]==0)
                    {
                        count++;
                        flower[i] = 1;
                    }
                }
            }
        }
        return (count>=n);
        }
}; 	
