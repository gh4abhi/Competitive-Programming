// Problem Link - https://leetcode.com/problems/long-pressed-name/

#define ll int

class Solution {
public:
    bool isLongPressedName(string pattern, string match) {
        ll i=0,j=0;
    ll flag = 1;
    char a = pattern[0],b = match[0];
    if(match.length()<pattern.length())
    {
        flag = 0;
    }
    else
    {
        while(j<match.length())
        {
            if(i==pattern.length())
            {
                break;    
            }
            
            if(pattern[i]==match[j])
            {
                a = pattern[i];
                i++;
                j++;
            }
            else
            {
                if(a==match[j])
                {
                    while(match[j]==a)
                    {
                        j++;
                    }
                }
                else
                {
                    flag = 0;
                    break;
                }
                
                if(pattern[i]!=match[j])
                {
                    flag = 0;
                    break;
                }
            }
        }
    }
    
    char ch = pattern[pattern.length()-1];
    if(j!=match.length())
    {
        while(j<match.length())
        {
            if(match[j]==ch)
            {
                j++;
            }
            else
            {
                flag = 0;
                break;
            }
        }
    }
    if(i!=pattern.length())
    {
        flag = 0;
    }
    if(flag)
    {
        return true;
    }
    else
    {
        return false;
    }
    }
};
