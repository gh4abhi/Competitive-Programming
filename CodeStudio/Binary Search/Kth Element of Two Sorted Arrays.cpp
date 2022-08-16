// Problem Link - https://www.codingninjas.com/codestudio/problems/1112629?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#define ll int

int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    if(row2.size()<row1.size())
        return ninjaAndLadoos(row2,row1,n,m,k);
    ll n1 = row1.size();
    ll n2 = row2.size();
    ll start = max(0,k-n2), end = min(n1,k);
    while(start<=end)
    {
        ll cut1 = start + (end-start)/2;
        ll cut2 = min(k - cut1,n2);
        ll l1 = (cut1==0)?-1e9:row1[cut1-1];
        ll r1 = (cut1==n1)?1e9:row1[cut1];
        ll l2 = (cut2==0)?-1e9:row2[cut2-1];
        ll r2 = (cut2==n2)?1e9:row2[cut2];
        if(max(l1,l2)<=min(r1,r2))
            return max(l1,l2);
        if(l1>r2)
            end = cut1-1;
        else
            start = cut1+1;
    }
    return 0;
}