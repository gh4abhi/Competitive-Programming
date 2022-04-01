// Problem Link - https://leetcode.com/problems/flood-fill/

#define ll int

class Solution {
public:
    
    void floodFillHelper(vector<vector<int>>& image, ll i, ll j, ll c, ll cur)
    {
        image[i][j] = c;
        if(i>0 and image[i-1][j]==cur)
            floodFillHelper(image, i-1, j, c,cur);
        if(j>0 and image[i][j-1]==cur)
            floodFillHelper(image, i, j-1, c,cur);
        if(i<image.size()-1 and image[i+1][j]==cur)
            floodFillHelper(image, i+1, j, c,cur);
        if(j<image[i].size()-1 and image[i][j+1]==cur)
            floodFillHelper(image, i, j+1, c,cur);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(newColor==image[sr][sc])
            return image;
        floodFillHelper(image, sr, sc, newColor,image[sr][sc]);
        return image;
    }
};