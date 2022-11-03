// Problem Link - https://www.codingninjas.com/codestudio/problems/2090383?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#define ll int

string longestCommonPrefix(vector<string> &arr, int n)
{
    string op = arr[0];
    for(ll i=1;i<arr.size();i++)
    {
        string ok = "";
        for(ll j=0;j<min(arr[i].length(),op.length());j++)
        {
            if(arr[i][j]==op[j])
                ok += op[j];
            else
                break;
        }
        op = ok;
    }
    return op;
}


