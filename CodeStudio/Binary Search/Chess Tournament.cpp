// Problem Link - https://www.codingninjas.com/codestudio/problems/chess-tournament_981299?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#define ll int

bool isPossible(vector<ll>& positions, ll x, ll c)
{
    ll op = 0;
    ll val = 0;
    for(auto i:positions)
        if(i>=val)
            op++, val = i+x;
    return op>=c;
}

int chessTournament(vector<int> positions , int n ,  int c){
    sort(positions.begin(),positions.end());
    ll start = 1, end = 1e18;
    while(start<=end)
    {
        ll mid = start + (end-start)/2;
        if(isPossible(positions,mid,c))
            start = mid + 1;
        else
            end = mid - 1;
    }
    return end;
}