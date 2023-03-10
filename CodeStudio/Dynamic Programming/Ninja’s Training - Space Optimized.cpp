// Problem Link - https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003?leftPanelTab=0

#define ll int

int ninjaTraining(int n, vector<vector<int>> &points)
{
    ll a = points[0][0];
    ll b = points[0][1];
    ll c = points[0][2];
    for(ll i = 1;i<points.size();i++)
    {
        ll ca = points[i][0] + max(b,c);
        ll cb = points[i][0] + max(b,c);
        points[i][2] += max(points[i-1][1],points[i-1][0]);
    }
    return max(points[n-1][0],max(points[n-1][1],points[n-1][2]));
}