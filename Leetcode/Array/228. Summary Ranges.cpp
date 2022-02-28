// Problem Link - https://leetcode.com/problems/summary-ranges/

#define ll int

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
       vector<string> ans;
        if(nums.size()==0)
            return ans;
        if(nums.size()==1)
        {
            string a = "";
            a+=to_string(nums[0]);
            ans.push_back(a);
            return ans;
        }
        string begin = to_string(nums[0]);
        ll check = nums[0];
        for(ll i=1;i<nums.size();i++)
        {
            if(nums[i]!=check+1)
            {
                if(begin==to_string(check))
                {
                    string a = "";
                    a += begin;
                    ans.push_back(a);
                }
                else
                {
                string a = "";
                string c = to_string(check);
                a += begin;
                a = a + "->" + c;    
                ans.push_back(a);                    
                }
                begin = to_string(nums[i]);
            }
                check = nums[i];
        }
         if(begin==to_string(check))
                {
                    string a = "";
                    a += begin;
                    ans.push_back(a);
                }
                else
                {
                string a = "";
                string c = to_string(check);
                a += begin;
                a = a + "->" + c;    
                ans.push_back(a);                    
                }
    return ans;
        }
};