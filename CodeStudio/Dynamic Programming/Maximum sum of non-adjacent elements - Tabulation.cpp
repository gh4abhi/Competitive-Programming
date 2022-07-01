// Problem Link - https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261?leftPanelTab=0

#define ll int

int maximumNonAdjacentSum(vector<int> &nums){
    if(nums.size()==1)
        return nums[0];
    vector<ll> dp(nums.size(),0);
    dp[nums.size()-1] = nums[nums.size()-1];
    for(ll i=nums.size()-2;i>=0;i--)
    {
        ll one = dp[i+1];
        ll two = nums[i];
        if(i<nums.size()-2)
            two+=dp[i+2];
        dp[i] = max(one,two);
    }
    return max(dp[0],dp[1]);
  
}