// Problem Link - https://leetcode.com/problems/kth-largest-element-in-an-array/

#define ll int

class Solution {
public:
    int findKthLargest(vector<int>& vect, int k) {
      for(ll i=0;i<k;i++)
      {
          for(ll j=0;j<vect.size()-i-1;j++)
          {
              if(vect[j]>vect[j+1])
              {
                  swap(vect[j],vect[j+1]);
              }
          }
      }
        return vect[vect.size()-k];
    }
};
