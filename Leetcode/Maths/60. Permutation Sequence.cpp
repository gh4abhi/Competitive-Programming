// Problem Link - https://leetcode.com/problems/permutation-sequence/

#define ll int

class Solution {
public:
    string getPermutation(int n, int k) {
        ll fact = 1;
        vector<ll> vect;
        for(ll i=1;i<n;i++)
            fact*=i, vect.push_back(i);
        vect.push_back(n);
        k-=1;
        string ans = "";
        while(1)
        {
            ans += to_string(vect[k/fact]);
            vect.erase(vect.begin()+k/fact);
            if(vect.size()==0)
                break;
            k = k%fact;
            fact = fact/vect.size();
        }
        return ans;
    }
};