// Problem Link - https://leetcode.com/problems/valid-palindrome-ii/

#define ll int

class Solution {
public:
    
    bool checkPalindrome(string s, ll l, ll r)
    {
        while(l<r)
        {
            if(s[l]!=s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    
    
    bool validPalindrome(string s) {
        ll left = 0, right = s.length()-1;
        while(s[left]==s[right] and left<right)
        {
            left++;
            right--;
        }
        ll flag1 = 1;
        ll flag2 = 1;
        if(left<right)
        {
            flag1 = checkPalindrome(s,left+1,right);
            flag2 = checkPalindrome(s,left, right-1);
        }
        
        if(!flag1 and !flag2)
            return false;
        return true;
        
    }
};