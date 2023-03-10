// Problem Link - https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003?leftPanelTab=0

#define ll int

int ninjaTraining(int n, vector<vector<int>> &points)
{
    for(ll i = 1;i<points.size();i++)
    {
        points[i][0] += max(points[i-1][1],points[i-1][2]);
        points[i][1] += max(points[i-1][0],points[i-1][2]);
        points[i][2] += max(points[i-1][1],points[i-1][0]);
    }
    return max(points[n-1][0],max(points[n-1][1],points[n-1][2]));
}