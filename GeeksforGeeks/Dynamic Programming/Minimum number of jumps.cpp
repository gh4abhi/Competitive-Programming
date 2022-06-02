// Problem Link - https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1/?page=1&difficulty[]=1&sortBy=submissions#

#define ll int

class Solution{
  public:
    int minJumps(int arr[], int n){
        if(n<=1)
            return 0;
        if(arr[0]==0)
            return -1;
        ll jump = 1;
        ll steps = arr[0];
        ll destination = arr[0];
        for(ll i=1;i<n;i++)
        {
            if(i==n-1)
                return jump;
            destination = max(destination,arr[i]+i);
            steps--;
            if(steps==0)
            {
                jump++;
                if(i>=destination)
                    return -1;
                steps = destination - i;
            }
        }
        return -1;
    }
};