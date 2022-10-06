// Problem Link - https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

#define ll int

struct meet
{
    ll start;
    ll end;
    ll ind;
};

bool cmp(struct meet &a, struct meet &b)
{
    if(a.end!=b.end)
        return a.end<b.end;
    return a.ind<b.ind;
}

class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        struct meet arr[n];
        for(ll i=0;i<n;i++)
            arr[i].start = start[i], arr[i].end = end[i], arr[i].ind = i;
        sort(arr,arr+n,cmp);
        ll ans = 0;
        ll mEnd = 0;
        for(ll i=0;i<n;i++)
            if(arr[i].start>mEnd)
                ans++, mEnd = arr[i].end;
        return ans;
    }
};
