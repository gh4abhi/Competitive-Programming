#define ll int

class Solution {
public:
    
    void permuteHelper(vector<ll>&ansPart, vector<int>& nums, vector<vector<ll>>& ans, ll freq[])
    {
        if(ansPart.size()==nums.size())
        {
            ans.push_back(ansPart);
            return;
        }
        for(ll i=0;i<nums.size();i++)
        {
            if(!freq[i])
            {
                ansPart.push_back(nums[i]);
                freq[i] = 1;
                permuteHelper(ansPart,nums,ans,freq);
                freq[i] = 0;
                ansPart.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
         vector<vector<ll>> ans;
         vector<ll> ansPart;
         ll freq[nums.size()];
        for(ll i=0;i<nums.size();i++) freq[i] = 0;
         permuteHelper(ansPart,nums,ans,freq);
        return ans;
    }
};
