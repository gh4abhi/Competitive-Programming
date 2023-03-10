// Problem Link - https://www.codingninjas.com/codestudio/problems/696444?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<bits/stdc++.h>
#define ll int

string reverseString(string s)
{
     vector<string> vect;
        s+=' ';
        string str = "";
        for(ll i=0;i<s.length();i++)
        {
            if(s[i]==' ')
            {
                while(i+1<s.length() and s[i+1]==' ')
                    i++;
                if(str.length())
                    vect.push_back(str);
                str="";
                continue;
            }
            if(s[i]!=' ')
                str += s[i];
        }
        reverse(vect.begin(),vect.end());
        str = "";
        for(auto i:vect)
            str+=i+' ';
        return str.substr(0,str.length()-1);
}