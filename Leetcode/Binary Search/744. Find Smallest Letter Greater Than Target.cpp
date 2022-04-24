// Problem Link - https://leetcode.com/problems/find-smallest-letter-greater-than-target/

#define ll int

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        ll n = letters.size();
        ll start = 0, end = n-1;
        while(start<=end)
        {
            ll mid = start + (end-start)/2;
            if(letters[mid]<=target)
                start = mid+1;
            else
                end = mid - 1;
        }
        return letters[start%n];
    }
};