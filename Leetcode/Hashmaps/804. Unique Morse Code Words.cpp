// Problem Link - https://leetcode.com/problems/unique-morse-code-words/

#define ll int

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> code= {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        map<string,ll> m;
        for(auto i:words)
        {
            string str = "";
            for(auto j:i)
                str += code[j-'a'];
            m[str]++;
        }
        return m.size();
    }
};