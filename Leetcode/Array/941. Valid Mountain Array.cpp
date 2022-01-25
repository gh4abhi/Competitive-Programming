// Problem Link - https://leetcode.com/problems/valid-mountain-array/

#define ll int

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        ll flag = 2;
        if(arr.size()==1 or arr.size()==2)
            return false;
        if(arr[0]<arr[1])
            flag = 0;
        for(ll i=1;i<arr.size();i++)
        {
            if(arr[i]==arr[i-1])
                return false;
            
            if(flag==0)
            {
                if(arr[i]<arr[i-1])
                {
                    flag = 1;
                }
            }
        if(flag==1)
        {
            if(arr[i]>arr[i-1])
            {
                return false;
            }
        }
        }
        if(flag==0 or flag==2)
            return false;
        return true;
    }
};
