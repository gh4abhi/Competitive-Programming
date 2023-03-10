// Problem Link - https://www.codingninjas.com/codestudio/problems/integer-to-roman-numeral_981307?leftPanelTab=0

#define ll long long
string intToRoman(int num) {
    vector<ll> intCode = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> code = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string ans = "";
        for(ll i=0;i<intCode.size();i++)
            while(intCode[i]<=num)
                ans += code[i], num -= intCode[i];
        return ans;
}
