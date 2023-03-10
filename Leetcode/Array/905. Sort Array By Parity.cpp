// Problem Link - https://leetcode.com/problems/sort-array-by-parity/

#define ll int

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[](ll &a, ll &b){
            return a%2<b%2;
        });
        return nums; 
    }
};