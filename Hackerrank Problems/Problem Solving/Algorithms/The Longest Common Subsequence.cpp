// Problem Link - https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence/problem

#include <bits/stdc++.h>
#define ll int

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'longestCommonSubsequence' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER_ARRAY b
 */

vector<int> longestCommonSubsequence(vector<int> a, vector<int> b) {
    ll m = a.size();
    ll n = b.size();
    vector<vector<ll>> dp(m+1,vector<ll>(n+1,0));
    for(ll i=m-1;i>=0;i--)
    {
        for(ll j=n-1;j>=0;j--)
        {
            if(a[i]==b[j])
                dp[i][j] = 1+dp[i+1][j+1];
            else
                dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
        }
    }
    vector<ll> ans;
    ll i=0;
    ll j=0;
    while(i<m and j<n)
    {
        if(a[i]==b[j])
            i++,j++,ans.push_back(a[i-1]);
        else
        {
            if(dp[i+1][j]>dp[i][j+1])
                i++;
            else
                j++;
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split(rtrim(a_temp_temp));

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    string b_temp_temp;
    getline(cin, b_temp_temp);

    vector<string> b_temp = split(rtrim(b_temp_temp));

    vector<int> b(m);

    for (int i = 0; i < m; i++) {
        int b_item = stoi(b_temp[i]);

        b[i] = b_item;
    }

    vector<int> result = longestCommonSubsequence(a, b);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
