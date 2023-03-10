// Problem Link - https://leetcode.com/problems/word-ladder/

#define ll int

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;
        bool isPresent = false;
        for(auto i:wordList)
        {
            if(i==endWord)
                isPresent = true;
            st.insert(i);
        }
        if(!isPresent)
            return 0;
        queue<string> nodes;
        nodes.push(beginWord);
        ll depth = 0;
        
        while(nodes.size()!=0)
        {
            depth++;
            ll levelSize = nodes.size();
            while(levelSize--)
            {
                string current = nodes.front();
                nodes.pop();
                
                for(ll j = 0; j<current.length();j++)
                {
                    string temp = current;
                    for(char c= 'a'; c<='z'; c++)
                    {
                        temp[j] = c;
                        
                        if(temp==current)
                            continue;
                        if(temp==endWord)
                            return depth+1;
                        if(st.find(temp)!=st.end())
                        {
                            nodes.push(temp);
                            st.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};
