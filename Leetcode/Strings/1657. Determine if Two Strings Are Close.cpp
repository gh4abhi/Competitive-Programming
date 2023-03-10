// Problem Link - https://leetcode.com/problems/determine-if-two-strings-are-close/

#define ll long long

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        map<char,ll> m1,m2;
        for(auto i:word1)
            m1[i]++;
        for(auto i:word2)
            m2[i]++;
        string s1="",s2="",s3="",s4="";
        for(auto i:m1)
            s1+=to_string(i.second),s3+=i.first;
        for(auto i:m2)
            s2+=to_string(i.second),s4+=i.first;
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        return (s1==s2 and s3==s4);
    }
};