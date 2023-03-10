// Problem Link - https://www.codingninjas.com/codestudio/problems/1062679?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#define ll int

double findNthRootOfM(int n, long long m) {
    double start = 1;
    double end = m;
    double eps = 1e-8;
    while(end-start>eps)
    {
        double mid = start + (end-start)/2.0;
        double op = 1.0;
        for(ll i=0;i<n;i++)
            op *= mid;
        if(op>m)
            end = mid;
        else 
            start = mid;
    }
    return start;
}
