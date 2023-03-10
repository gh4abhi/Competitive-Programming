// Problem Link - https://leetcode.com/problems/reverse-vowels-of-a-string/

#define ll int

class Solution {
public:
    string reverseVowels(string s) {
        vector<ll> vowels;
        ll count = 0;
        for(auto i:s)
        {
            if(i=='a' or i=='A' or i=='e' or i=='E' or i=='i' or i=='I' or i=='o' or i=='O' or i=='u' or i=='U')
                vowels.push_back(count);
            count++;
        }
        ll i =0, j = vowels.size()-1;
        while(i<j)
        {
            swap(s[vowels[i]],s[vowels[j]]);
            i++;
            j--;
        }
        return s;
    }
};