// Problem Link - https://practice.geeksforgeeks.org/problems/word-search/1?page=2&company[]=Amazon&category[]=Graph&sortBy=submissions

#define ll int

class Solution {
public:
    bool DFS(vector<vector<char>>& board, string word, string op, vector<vector<ll>> &vis, ll i, ll j)
    {
        ll m = board.size();
        ll n = board[0].size();
        vis[i][j] = 1;
        op += board[i][j];
        if(op.length()>word.length())
        {
            vis[i][j] = 0;
            return false;
        }
        if(op[op.length()-1]!=word[op.length()-1])
        {
            vis[i][j] = 0;
            return false;
        }
        if(op==word)
            return true;
        if(i-1>=0 and vis[i-1][j]==0)
            if(DFS(board,word,op,vis,i-1,j))
                return true;
        if(j-1>=0 and vis[i][j-1]==0)
            if(DFS(board,word,op,vis,i,j-1))
                return true;
        if(i+1<m and vis[i+1][j]==0)
            if(DFS(board,word,op,vis,i+1,j))
                return true;
        if(j+1<n and vis[i][j+1]==0)
            if(DFS(board,word,op,vis,i,j+1))
                return true;
        vis[i][j] = 0;
        return false;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        ll m = board.size();
        ll n = board[0].size();
        for(ll i=0;i<m;i++)
        {
            for(ll j=0;j<n;j++)
            {
                if(board[i][j]==word[0]){
                vector<vector<ll>> vis(m,vector<ll>(n,0));
                if(DFS(board,word,"",vis,i,j))
                    return true;
                }
            }
        }
        return false;
    }
};