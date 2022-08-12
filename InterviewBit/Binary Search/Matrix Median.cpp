// Problem Link - https://www.interviewbit.com/problems/matrix-median/

#define ll long long

ll numSmall(vector<int> vect, ll x)
{
    ll start = 0, end = vect.size()-1;
    while(start<=end)
    {
        ll mid = start + (end-start)/2;
        if(vect[mid]<=x)
            start = mid + 1;
        else
            end = mid - 1;    
    }    
    return start;
}

int Solution::findMedian(vector<vector<int> > &A) {
    ll start = 1, end = 1e10;
    ll n = A.size(), m = A[0].size();
    while(start<=end)
    {
        ll mid = start + (end-start)/2;
        ll count = 0;
        for(auto i:A)
            count += upper_bound(i.begin(),i.end(),mid) - i.begin();
        if(count<=(n*m)/2)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return start;
}