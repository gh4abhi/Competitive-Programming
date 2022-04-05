// problem Link - https://leetcode.com/problems/check-if-word-can-be-placed-in-crossword/

#define ll int

class Solution {
public:
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        vector<string> ltr, ttb;
        for(ll i=0;i<board.size();i++)
        {
            string s = "";
            for(ll j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='#' or j== board[0].size()-1)
                {
                    if(j==board[0].size()-1 and board[i][j]!='#')
                        s+= board[i][j];
                    if(s.length()>0)
                     ltr.push_back(s);
                    s = "";
                }
                else
            s+= board[i][j];
            }
        }
        for(ll i=0;i<board[0].size();i++)
        {
            string s = "";
            for(ll j=0;j<board.size();j++)
            {
                if(board[j][i]=='#' or j== board.size()-1)
                {
                    if(j==board.size()-1 and board[j][i]!='#')
                        s+= board[j][i];
                    if(s.length()>0)
                     ttb.push_back(s);
                    s = "";
                }
                else
                s+= board[j][i];
            }
        }
        for(auto i:ltr)
        {
            string str = i;
           // cout<<i<<endl;
            if(str.length()==word.length())
            {
                ll flag1 = 1;
                ll flag2 = 1;
                for(ll j = 0; j<str.length();j++)
                {
                    if(str[j]!=' ' and word[j]!=str[j])
                       {flag1 = 0;
                        break;}
                }
                reverse(str.begin(),str.end());
                for(ll j = 0; j<str.length();j++)
                {
                    if(str[j]!=' ' and word[j]!=str[j])
                       {flag2 = 0;
                        break;}
                }
                if(flag1 or flag2)
                    return true;
            }
            
        }
        for(auto i:ttb)
        {
            string str = i;
           // cout<<i<<endl;
            if(str.length()==word.length())
            {
                ll flag1 = 1;
                ll flag2 = 1;
                for(ll j = 0; j<str.length();j++)
                {
                    if(str[j]!=' ' and word[j]!=str[j])
                       {flag1 = 0;
                        break;}
                }
                reverse(str.begin(),str.end());
                for(ll j = 0; j<str.length();j++)
                {
                    if(str[j]!=' ' and word[j]!=str[j])
                       {flag2 = 0;
                        break;}
                }
                if(flag1 or flag2)
                    return true;
            }
            
        }
        // cout<<"h";
        return false;
    }
};