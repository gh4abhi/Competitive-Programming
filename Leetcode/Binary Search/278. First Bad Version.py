# Problem Link - https://leetcode.com/problems/first-bad-version/
# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        i = 1
        j = n
        ans = float("inf")
        while i<=j:
            mid = (i+j)//2
            if(isBadVersion(mid)==True):
                ans = min(mid,ans)
                j = mid - 1
            else:
                i = mid + 1
        return ans