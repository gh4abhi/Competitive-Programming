#define ll int
int solve(vector<int>& nums) {
    ll count = 0;
    for(auto i:nums)
    {
        ll val = i;
        ll d = 0;
        while(val)
        {
            d+=1;
            val/=10;
        }
        if(d&1)
        count++;
    }
    return count;
}
