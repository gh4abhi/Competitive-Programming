// Problem Link - https://leetcode.com/problems/range-sum-query-immutable/

#define ll int 

class NumArray {
public:
    vector<ll> vect;
    NumArray(vector<int>& nums) {
        for(ll i=1;i<nums.size();i++)
            nums[i] += nums[i-1];
        vect = nums;
    }
    
    int sumRange(int left, int right) {
        if(left==0)
            return vect[right];
        return vect[right]-vect[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */