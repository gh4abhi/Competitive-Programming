// Problem Link - https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/

class Solution {
    public int minPartitions(String n) {
        int sum = 0;
        int maxi = 0;
        for(int i=0;i<n.length();i++)
        {
            int val = n.charAt(i)-'0';
            if(maxi<val)
            {
                sum += (val-maxi);
                maxi = val;
            }
        }
        return sum;
    }
}