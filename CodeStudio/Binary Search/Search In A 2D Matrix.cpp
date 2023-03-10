// Problem Link - https://www.codingninjas.com/codestudio/problems/980531?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
#define ll long long
#include <vector>

bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    ll start = 0, end = m*n-1;
    while(start<=end)
    {
        ll mid = start + (end-start)/2;
        ll op = mat[mid/n][mid%n];
        if(op==target)
            return true;
        else if(op>target)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return false;
}