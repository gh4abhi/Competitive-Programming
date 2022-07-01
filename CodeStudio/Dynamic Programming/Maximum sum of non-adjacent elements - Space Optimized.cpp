// Problem Link - https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261?leftPanelTab=0

#define ll int

int maximumNonAdjacentSum(vector<int> &nums){
    if(nums.size()==1)
        return nums[0];
    ll a = 0,b = nums[nums.size()-1];
    for(ll i=nums.size()-2;i>=0;i--)
    {
        ll one = b;
        ll two = nums[i] + a;
        ll curr = max(one,two);
        a = b;
        b = curr;
    }
    return b;
  
}