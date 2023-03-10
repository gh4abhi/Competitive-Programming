/ Problem Link - https://www.codingninjas.com/codestudio/problems/1115474?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#define ll int

int maximumProduct(vector<int> &arr, int n)
{
    ll ans = INT_MIN;
    ll op = 1;
    for(ll i=0;i<n;i++)
    {
        op *= arr[i];
        ans = max(ans,op);
        if(op==0)
            op = 1;
    }
    op = 1;
    for(ll i=n-1;i>=0;i--)
    {
        op *= arr[i];
        ans = max(ans,op);
        if(op==0)
            op = 1;
    }
    return ans;
}
