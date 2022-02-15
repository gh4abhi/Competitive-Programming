#define ll int

int solve(vector<int>& piles) {
    sort(piles.begin(),piles.end(),greater<ll>());
    ll maxi = 0;
    ll i=0,j=piles.size()-1;
    while(i<j)
    {
        maxi+=piles[i+1];
        i+=2;
        j--;
    }
    return maxi;
}
