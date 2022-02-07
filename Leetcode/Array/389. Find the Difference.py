# Problem Link - https://leetcode.com/problems/find-the-difference/

class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        di = {}
        for i in s:
            if(i not in di.keys()):
                di.update({i:1})
            else:
                di[i] = di[i] + 1
        for i in t:
            if i not in di.keys():
                return i
            if di[i]==1:
                di.pop(i)
            else :
                di[i] = di[i] -1