// Problem Link - https://leetcode.com/contest/weekly-contest-302/problems/query-kth-smallest-trimmed-number/

class Solution {
public:
    string calculate(string s,int t){
        int n = s.size();
        return s.substr(n-t,t);
    }
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int s = nums[0].size();
        int q = queries.size();
        vector<int>ans;
        for(int i=0;i<q;i++){
            int k = queries[i][0];
            int t = queries[i][1];
            priority_queue<pair<string,int>>pq;
            for(int j=0;j<n;j++){
                string number = calculate(nums[j],t);
                pq.push({number,j});
                if(pq.size()>k)pq.pop();
            }
            ans.push_back(pq.top().second);
        }
        return ans;
    }
};