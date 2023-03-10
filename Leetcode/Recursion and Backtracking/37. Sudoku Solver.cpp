// Problem Link - https://leetcode.com/problems/sudoku-solver/

#define ll int

class Solution {
public:
    
    bool isPossible(vector<vector<char>> &board, ll r, ll c, char ch)
    {
        for(ll i=0;i<9;i++)
        {
            if(board[i][c]==ch)
                return false;
            if(board[r][i]==ch)
                return false;
            if(board[3*(r/3) + i/3][3*(c/3) + i%3]==ch)
                return false;
        }
        return true;
    }
    
    bool DFS(vector<vector<char>> &board)
    {
        for(ll i=0;i<board.size();i++){
            for(ll j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    for(char ch='1'; ch<='9';ch++){
                        if(isPossible(board,i,j,ch)){
                            board[i][j] = ch;
                            if(DFS(board))
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        DFS(board);
    }
};