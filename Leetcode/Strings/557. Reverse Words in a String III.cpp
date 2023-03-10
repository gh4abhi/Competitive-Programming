// Poblem Link - https://leetcode.com/problems/reverse-words-in-a-string-iii/

#define ll int

class Solution {
public:
    string reverseWords(string s) {
        vector<string> vect;
        s+=' ';
        string str = "";
        for(auto i:s)
        {
            if(i==' ')
            {
                if(str.length()>0)
                vect.push_back(str);
                str = "";
            }
            else
            {
                str += i;
            }
        }
        string ans = "";
        for(auto i:vect)
        {
            ll start = 0, end = i.length()-1;
            while(start<end)
            {
                swap(i[start],i[end]);
                start++;
                end--;
            }
            ans += i;
            ans += ' ';
        }
        return ans.substr(0,ans.length()-1);
    }
};