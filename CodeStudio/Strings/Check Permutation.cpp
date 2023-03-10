// Problem Link - https://www.codingninjas.com/codestudio/problems/1172164?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
#define ll int
bool areAnagram(string &s, string &t){
        unordered_map<char,ll> m1,m2;
        for(auto i:s)
            m1[i]++;
        for(auto i:t)
            m2[i]++;
        return m1==m2;
}