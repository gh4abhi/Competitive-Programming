// Problem Link - https://leetcode.com/problems/count-common-words-with-one-occurrence/

#define ll int
using namespace std;
class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        
        map<string,ll> m1,m2;
        for(auto i:words1)
        {
            m1[i]++;
        }
        for(auto i: words2)
        {
            m2[i]++;
        }
        
        if(words1.size()<words2.size())
        {
            swap(words1,words2);
        }
        
        ll count  = 0;
        
        for(auto i:words1)
        {
            if(m1[i]==1 and m2[i]==1)
                count++;
        }
        
        return count;
    }
};
