// Problem Link - https://practice.geeksforgeeks.org/problems/number-of-occurrence2259/1

#define ll int

class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	
	int firstOcc(ll arr[], ll n, ll x)
	{
	    ll l = 0, r = n-1;
	    ll ans = -1;
	    while(l<=r)
	    {
	        ll mid = (l) + (r-l)/2;
	        if(arr[mid]<x)
	        {
	            l = mid+1;
	        }
	        else if(arr[mid]>x)
	        {
	            r = mid-1;
	        }
	        else
	        {
	            ans = mid;
	            r = mid-1;
	        }
	    }
	    return ans;
	}
	
	ll lastOcc(ll arr[], ll n, ll x)
	{
	    ll l = 0, r = n-1;
	    ll ans = -1;
	    while(l<=r)
	    {
	        ll mid = (l) + (r-l)/2;
	        if(arr[mid]<x)
	        {
	            l = mid+1;
	        }
	        else if(arr[mid]>x)
	        {
	            r = mid-1;
	        }
	        else
	        {
	            ans = mid;
	            l = mid+1;
	        }
	    }
	       return ans;
	}
	
	int count(int arr[], int n, int x) {
	    ll first = firstOcc(arr, n, x);
	    ll last = lastOcc(arr, n, x);
	    if(first==-1)
	        return 0;
	    return (last-first+1);
	}
};
