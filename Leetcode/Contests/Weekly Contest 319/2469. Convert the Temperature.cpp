// Problem Link - https://leetcode.com/contest/weekly-contest-319/problems/convert-the-temperature/

class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        double ok = celsius + 273.15;
        double op = celsius * 1.80 + 32.00;
        return {ok,op};
    }
};