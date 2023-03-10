// Problem Link - https://www.codingninjas.com/codestudio/problems/985294?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#define ll int

double median(vector<int> a, vector<int> b)
{
    if(b.size()<a.size())
        return median(b,a);
    ll n1 = a.size(), n2 = b.size();
    ll start = 0, end = n1;
    while(start<=end)
    {
        ll cut1 = start + (end-start)/2;
        ll cut2 = (n1+n2+1)/2 - cut1;
        ll l1 = (cut1==0)?-1e9:a[cut1-1];
        ll r1 = (cut1==n1)?1e9:a[cut1];
        ll l2 = (cut2==0)?-1e9:b[cut2-1];
        ll r2 = (cut2==n2)?1e9:b[cut2];
        if(l1<=r2 and l2<=r1)
        {
            if((n1+n2)&1)
                return max(l1,l2);
            return (max(l1,l2)+min(r1,r2))/2.0;
        }
        if(l1>r2)
            end = cut1-1;
        else
            start = cut1 + 1;
    }
    return -1.0;
}
