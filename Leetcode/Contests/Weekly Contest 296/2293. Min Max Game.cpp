// Problem Link - https://leetcode.com/contest/weekly-contest-296/problems/min-max-game/

#define ll long long

class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        vector<int> vect = nums;
        while(vect.size()>1)
        {
            vector<int> temp;
            for(ll i=0;i<vect.size()/2;i++)
            {
                if(i%2==0)
                temp.push_back(min(vect[2*i],vect[2*i+1]));
                else
                temp.push_back(max(vect[2*i],vect[2*i+1]));
                }
            vect=temp;
        }
        return vect[0];
    }
};