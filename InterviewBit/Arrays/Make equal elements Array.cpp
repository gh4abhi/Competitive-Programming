// Problem Link - https://www.interviewbit.com/problems/make-equal-elements-array/

#define ll int
int Solution::solve(vector<int> &A, int B) {
 for(ll i=1;i<A.size();i++)
     if(abs(A[i]-A[i-1])%B!=0)
        return 0;
 return 1;
}