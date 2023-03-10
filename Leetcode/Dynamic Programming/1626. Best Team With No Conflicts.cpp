// Problem Link - https://leetcode.com/problems/best-team-with-no-conflicts/

#define ll int

class Solution {
public:

    ll dp[1001][1002];

    ll best(ll ind, vector<ll> &ages, vector<ll>&scores, vector<ll> &vect, ll pre)
    {
        if(ind==vect.size())
            return 0;
        if(dp[ind][pre]!=-1)
            return dp[ind][pre];
        if(ages[vect[ind]]<=pre)
            return dp[ind][pre] = max(scores[vect[ind]] + best(ind+1,ages,scores,vect,ages[vect[ind]]), best(ind+1,ages,scores,vect,pre));
        return dp[ind][pre] = best(ind+1,ages,scores,vect,pre);
    }

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        ll n = scores.size();
        vector<ll> vect(n);
        for(ll i=0;i<n;i++)
            vect[i] = i;
        memset(dp,-1,sizeof(dp));
        sort(vect.begin(),vect.end(),[&scores, &ages](ll &a, ll&b){
            if(scores[a]!=scores[b])
                return scores[a]>scores[b];
            return ages[a]>ages[b];
        });
        return best(0,ages,scores,vect,1e3+1);
    }
};