// Problem Link - https://leetcode.com/problems/n-queens/

#define ll int

class Solution {
public:
    vector<vector<string>> ans;
    bool isPossible(ll n, ll row, ll col, vector<vector<char>>& board)
{
    for(ll i=row-1;i>=0;i--)
        if(board[i][col]=='Q')
            return false;
    for(ll i=row-1,j=col-1;i>=0 and j>=0;i--,j--)
        if(board[i][j]=='Q')
            return false;
    for(ll i=row-1,j=col+1;i>=0 and j<n;i--,j++)
        if(board[i][j]=='Q')
            return false;
    return true;
}

void nQueenHelper(ll n, vector<vector<char>>& board, ll row)
{
    if(row==n)
    {
        vector<string> temp;
        for(auto i:board)
        {
            string str = "";
            for(auto j:i)
                str+=j;
            temp.push_back(str);
        }
        ans.push_back(temp);
    }

    for(ll j=0;j<n;j++)
    {
        if(isPossible(n,row,j,board))
        {
            board[row][j] = 'Q';
            nQueenHelper(n,board,row+1);
            board[row][j] = '.';
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n,vector<char>(n,'.'));
        nQueenHelper(n,board,0);
        return ans;
    }
};