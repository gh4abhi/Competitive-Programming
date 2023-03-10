// Problem Link - https://practice.geeksforgeeks.org/problems/shortest-path-from-1-to-n0156/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

#define ll long long

class Solution{   
public:
    
    int minimumStep(int n){
        ll op = 1;
        ll ans = 0;
        while(n>1)
        {
            if(n%3==0)
                n/=3;
            else
                n-=1;
            ans+=1;
        }
        return ans;
    }
};