// Problem Link - https://practice.geeksforgeeks.org/problems/set-bits0143/1#

class Solution{
  public:
    int setBits(int N) {
        int ans = 0;
        int val = 1;
        while(val<=N)
        {
            if(val&N)
                ans++;
            val*=2;
        }
        return ans;
    }
};