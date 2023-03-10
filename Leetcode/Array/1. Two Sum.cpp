// Problem Link - https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        vector<int> vect,nums1;
        nums1=nums;
        sort(nums1.begin(),nums1.end());
        while(i<j)
        {
            int sum = nums1[i] + nums1[j];
            if(sum<target)
            {
                i++;
            }
            else if(sum>target)
            {
                j--;
            }
            else
            {
                vect.push_back(find(nums.begin(),nums.end(),nums1[i])-nums.begin());
                nums[find(nums.begin(),nums.end(),nums1[i])-nums.begin()] = nums1[nums.size()-1]+1;
                vect.push_back(find(nums.begin(),nums.end(),nums1[j])-nums.begin());
                nums[find(nums.begin(),nums.end(),nums1[j])-nums.begin()] = nums1[nums.size()-1]+1;
                break;
            }
        }
        return vect;
    }
};
