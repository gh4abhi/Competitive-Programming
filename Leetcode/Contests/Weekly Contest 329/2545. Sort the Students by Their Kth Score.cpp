// Problem Link - https://leetcode.com/contest/weekly-contest-329/problems/sort-the-students-by-their-kth-score/

#define ll int

class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        sort(score.begin(),score.end(),[&k](vector<ll> &a, vector<ll> &b){
            return a[k]>b[k];
        });
        return score; 
    }
};