// Problem Link - https://www.codingninjas.com/codestudio/problems/the-celebrity-problem_982769?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0 

#include <bits/stdc++.h> 
#define ll int

/*
    This is signature of helper function 'knows'.
    You should not implement it, or speculate about its implementation.

    bool knows(int A, int B); 
    Function 'knows(A, B)' will returns "true" if the person having
    id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
    ll c = 0;
    for(ll i=1;i<n;i++)
        if(knows(c,i))
            c = i;
    for(ll i=0;i<n;i++)
        if(i!=c and (!knows(i,c) or knows(c,i)))
            return -1;
    return c;
}