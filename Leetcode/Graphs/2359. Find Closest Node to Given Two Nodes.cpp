// Problem Link - https://leetcode.com/problems/find-closest-node-to-given-two-nodes/

#define ll int

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        queue<ll> q;
        q.push(node1);
        ll n = edges.size();
        vector<ll> dis1(n,1e9);
        dis1[node1] = 0;
        map<ll,ll> vis1;
        while(q.size())
        {
            auto cur = q.front();
            q.pop();
            vis1[cur]++;
            if(vis1.count(edges[cur])==0 and edges[cur]!=-1)
                dis1[edges[cur]] = dis1[cur] + 1, q.push(edges[cur]);
            else if(edges[cur]!=-1)
                dis1[edges[cur]] = min(dis1[edges[cur]], 1 + dis1[cur]);
        }
        vector<ll> dis2(n,1e9);
        dis2[node2] = 0;
        map<ll,ll> vis2;
        q.push(node2);
        while(q.size())
        {
            auto cur = q.front();
            q.pop();
            vis2[cur]++;
            if(vis2.count(edges[cur])==0 and edges[cur]!=-1)
                dis2[edges[cur]] = dis2[cur] + 1, q.push(edges[cur]);
            else if(edges[cur]!=-1) 
                dis2[edges[cur]] = min(dis2[edges[cur]], 1 + dis2[cur]);
        }
        ll ans = 1e9;
        ll ind = -1;
        for(ll i=0;i<n;i++)
            if(max(dis1[i],dis2[i])<ans)
                ans = max(dis1[i],dis2[i]), ind = i;
        return ind;
    }
};