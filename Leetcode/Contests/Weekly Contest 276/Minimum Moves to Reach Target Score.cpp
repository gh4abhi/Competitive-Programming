// Problem Link - https://leetcode.com/contest/weekly-contest-276/problems/minimum-moves-to-reach-target-score/

#define ll int

class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        ll count = 0;
        if(target&1)
        {
            target--;
            count++;
        }
        while(1)
        {
            if(maxDoubles==0 or target<=1)
            {
                break;
            }
            if(target&1)
            {
                target--;
                count++;
                continue;
            }
            target/=2;
            count++;
            maxDoubles--;
        }
        count += target-1;
        return count;
    }
};
