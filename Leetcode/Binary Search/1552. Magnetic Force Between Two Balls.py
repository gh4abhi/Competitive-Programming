# Problem Link - https://leetcode.com/problems/magnetic-force-between-two-balls/

class Solution:
    def maxDistance(self, position: List[int], m: int) -> int:
        start = 0
        position.sort()
        end = position[-1] - position[0]
        ans = -1
        while start<=end:
            mid = start + (end-start)//2
            flag = 0
            last_position = 0
            count = 1
            for i in range(1,len(position)):
                if position[i] - position[last_position] >= mid:
                    count = count + 1
                    last_position = i
                if count == m:
                    flag = 1
                    break
            if flag:
                ans = max(ans,mid)
                start = mid + 1
            else:
                end = mid - 1
        return ans
        