// Problem Link - https://leetcode.com/problems/broken-calculator/

#define ll int

class Solution {
public:
    int brokenCalc(int startValue, int target) {
       ll count = 0;
        if(startValue>=target)
            return startValue - target;
        while(target>startValue)
        {
            if(target%2==0)
            {
                target = target/2;
                count++;
            }
            else
            {
                target = target/2;
                target++;
                count+=2;
            }
        }
        if(target==startValue)
            return count;
        return count+(startValue - target);
    }
};