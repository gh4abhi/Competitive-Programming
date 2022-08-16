// Problem Link - https://www.interviewbit.com/problems/allocate-books/

#define ll int

bool isPossible(vector<ll> &A, ll x, ll B)
{
    ll student = 1, pages = 0;
    for(auto i:A)
    {
        if(pages+i>x)
        {
            if(i>x)
                return false;
            pages = i;
            student++;    
        }
        else
            pages += i;
    }
    return student<=B;
}

int Solution::books(vector<int> &A, int B) {
    if(A.size()<B)
        return -1;
    ll end = 0, start = 1e18;
    for(auto i:A)
        end += i, start = min(start,i);
    while(start<=end)
    {
        ll mid = start + (end-start)/2;
        if(isPossible(A,mid,B))
            end = mid - 1;
        else
            start = mid + 1;
    }
    return start;
}
