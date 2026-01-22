from typing import List

# IMPORTANT: for a set to be divided into 2 equal sum, the sum has to be total/2


class Solution:
    dp: List[List[bool]]
    nums: List[int]

    def subsetSum(self, total: int, i: int):
        if total == 0:
            return True
        if i == 0:
            return False

        if self.dp[total][i] is not None:
            return self.dp[total][i]

        if self.nums[i] > total:
            self.dp[total][i] = self.subsetSum(total, i - 1)
            return self.dp[total][i]

        self.dp[total][i] = self.subsetSum(total, i - 1) or self.subsetSum(
            total - self.nums[i], i - 1
        )
        return self.dp[total][i]

    def canPartition(self, nums: List[int]) -> bool:
        if sum(nums) % 2 == 1:
            return False

        self.nums = nums

        total = sum(nums) // 2

        self.dp = [[None] * len(nums) for _ in range(total + 1)]

        return self.subsetSum(total, len(self.nums) - 1)
