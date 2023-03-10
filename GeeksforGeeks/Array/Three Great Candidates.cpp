// Problem Link - https://practice.geeksforgeeks.org/problems/three-great-candidates0515/1

#define ll long long

class Solution{   
public:
    long long maxProduct(int arr[], int n) {
        ll maxi = LONG_MIN, smaxi = LONG_MIN, tmaxi = LONG_MIN;
        ll mini = LONG_MAX, smini = LONG_MAX; 
        for(ll i=0;i<n;i++)
        {
            if(arr[i]>maxi)
                tmaxi = max(smaxi,tmaxi), smaxi = max(smaxi,maxi), maxi = arr[i];
            else if(arr[i]>smaxi)
                tmaxi = max(tmaxi, smaxi), smaxi = arr[i];
            else if(arr[i]>tmaxi)
                tmaxi = arr[i];
            if(arr[i]<mini)
                smini = min(mini,smini), mini = arr[i];
            else if(arr[i]<smini)
                smini = arr[i];
        }
        ll ans = maxi*smaxi*tmaxi;
        ans = max(smini*mini*maxi,ans);
        return ans;
    }
};