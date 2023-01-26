// Problem Link - https://practice.geeksforgeeks.org/problems/case-specific-sorting-of-strings4845/1

#define ll int

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        string a = "", b = "";
        for(auto i:str)
        {
            if(i>='a' and i<='z')
                b += i;
            else
                a += i;
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        ll ind = 0, j = 0;
        string ans = "";
        for(auto i:str)
        {
            if(i>='a' and i<='z')
                ans += b[ind++];
            else
                ans += a[j++];
        }
        return ans;
    }
};