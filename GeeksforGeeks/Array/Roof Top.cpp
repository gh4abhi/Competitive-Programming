// Problem Link - https://practice.geeksforgeeks.org/problems/roof-top-1587115621/1

#define ll int

class Solution
{
    public:
    //Function to find maximum number of consecutive steps 
    //to gain an increase in altitude with each step.
    int maxStep(int arr[], int n)
    {
       ll ans = 0;
       ll op = 0;
       for(ll i=1;i<n;i++)
       {
            if(arr[i]>arr[i-1])
                op+=1;
            else
                op = 0;
            ans = max(ans,op);
       }
       return ans;
    }
};