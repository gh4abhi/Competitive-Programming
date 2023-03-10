// Problem Link - https://leetcode.com/problems/satisfiability-of-equality-equations/

#define ll int

class Solution {
public:
    
    char findPar(char u, unordered_map<char,char> &par)
    {
        if(par[u]==u)
            return u;
        return par[u] = findPar(par[u],par);
    }
    
    void setUnion(char a, char b, unordered_map<char,char> &par, unordered_map<char,ll> &rank)
    {
        char p1 = findPar(a,par);
        char p2 = findPar(b,par);
        if(p1!=p2)
        {
            if(rank[p1]<rank[p2])
                par[p1] = p2;
            else if(rank[p1]>rank[p2])
                par[p2] = p1;
            else
                par[p2] = p1, rank[p1]++;
        }
    }
    
    bool equationsPossible(vector<string>& equations) {
        unordered_map<char,char> par;
        unordered_map<char,ll> rank;
        for(auto i:equations)
            par[i[0]] = i[0], par[i[3]] = i[3], rank[i[0]] = 0, rank[i[3]] = 0;
        for(auto i:equations)
            if(i[1]==i[2])
                setUnion(i[0],i[3],par,rank);
        for(auto i:equations)
            if(i[1]!=i[2])
                if(findPar(i[0],par)==findPar(par[i[3]],par))
                    return false;
        return true;
    }
};