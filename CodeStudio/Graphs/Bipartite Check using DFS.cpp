// Problem Link - https://www.codingninjas.com/codestudio/problems/920551?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#define ll int

bool colorGraph(ll start, vector<ll>& color, vector<vector<ll>>& edges)
{
    for(ll i=0;i<edges.size();i++)
    {
        if(edges[start][i]==1)
        {
            if(color[i]==-1)
            {
                color[i] = !color[start];
                if(!colorGraph(i,color,edges))
                    return false;
            }
            else if(color[i]==color[start])
                return false;
        }
    }
    return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
    vector<ll> color(edges.size(),-1);
    for(ll i=0;i<edges.size();i++)
        if(color[i]==-1)
        {
            color[i] = 1;
            if(!colorGraph(i,color,edges))
                return false;
        }
    return true;
}