// Problem Link - https://leetcode.com/contest/biweekly-contest-72/problems/find-three-consecutive-integers-that-sum-to-a-given-number/

#define ll long long

class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<ll> vect;
       if((num)%3==0)
       { 
           ll i = (num)/3;
           vect.push_back(i);
                vect.push_back(i+1);
                vect.push_back(i+2);
        }
    return vect;
    }
};