// Problem Link - https://leetcode.com/problems/surrounded-regions/

#define ll int

class Solution {
public:
    
    void boundaryCall(vector<vector<char>>& board, vector<vector<bool>>& visited, ll i, ll j, ll m, ll n)
    {
        visited[i][j] = true;
        board[i][j] = '1';
        if(i<n-1 and visited[i+1][j]==false and board[i+1][j]=='O')  
            boundaryCall(board, visited, i+1, j, m , n);
        if(i>0 and visited[i-1][j]==false and board[i-1][j]=='O')
            boundaryCall(board, visited, i-1, j, m, n);
        if(j<m-1 and visited[i][j+1]==false and board[i][j+1]=='O')
            boundaryCall(board, visited, i,j+1, m,n);
        if(j>0 and visited[i][j-1]==false and board[i][j-1]=='O')
            boundaryCall(board, visited, i, j-1,m,n);
    }
    
    
    void solve(vector<vector<char>>& board) {
        ll n = board.size();
        ll m = board[0].size();
        
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        
        for(ll i=0;i<n;i++)
        {
            if(visited[i][0]==false and board[i][0]=='O')
                boundaryCall(board, visited, i, 0, m, n);
            if(visited[i][m-1]==false and board[i][m-1]=='O')
                boundaryCall(board, visited, i, m-1, m, n);    
        }
        for(ll j=0;j<m;j++)
        {
            if(visited[0][j]==false and board[0][j]=='O')
                boundaryCall(board, visited, 0, j, m, n);
            if(visited[n-1][j]==false and board[n-1][j]=='O')
                boundaryCall(board, visited, n-1, j, m, n);    
        }
        
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<m;j++)
            {
                if(board[i][j]=='1')
                    board[i][j] = 'O';
                else if(board[i][j]=='O')
                    board[i][j] = 'X';
            }
        }
        
    }
};
