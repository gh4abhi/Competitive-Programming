// Problem Link - https://leetcode.com/problems/valid-sudoku/

#define ll int

class Solution {
public:
    
    bool isValidHelper(ll r, ll c, vector<vector<char>>& board)
    {
        map<char,ll>m;
        for(ll i=r;i<r+3;i++)
        {
            for(ll j=c; j<c+3;j++)
            {
                if(board[i][j]!='.')
                     m[board[i][j]]++;
                if(m[board[i][j]]>1)
                    return false;
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for(ll i=0;i<board.size();i++)
        {
            map<char,ll> m;
            for(ll j=0;j<board[0].size();j++)
            {
                if(board[i][j]!='.')
                    m[board[i][j]]++;
                if(m[board[i][j]]>1)
                    return false;
            }
        }
        for(ll i=0;i<board[0].size();i++)
        {
            map<char,ll> m;
            for(ll j=0;j<board.size();j++)
            {
                if(board[j][i]!='.')
                    m[board[j][i]]++;
                if(m[board[j][i]]>1)
                    return false;
            }
        }
        if(isValidHelper(0,0,board) and isValidHelper(0,3,board) and isValidHelper(0,6,board) and isValidHelper(3,0,board) and isValidHelper(3,3,board) and isValidHelper(3,6,board) and isValidHelper(6,0,board) and isValidHelper(6,3,board) and isValidHelper(6,6,board))
        return true;
        return false;
    }
};