from typing import List


def subset_sum(set: List[int], sum: int, i: int, dp: List[List[int]]):
    if sum == 0:
        return True
    if i == 0:
        return False

    if dp[sum][i] is not None:
        return dp[sum][i]

    if set[i] > sum:
        dp[sum][i] = subset_sum(set, sum, i - 1, dp)
        return dp[sum][i]

    dp[sum][i] = subset_sum(set, sum, i - 1, dp) or subset_sum(
        set, sum - set[i], i - 1, dp
    )
    return dp[sum][i]


if __name__ == "__main__":
    set = [3, 34, 4, 12, 5, 2]
    sum = 9
    dp = [[None] * len(set) for _ in range(sum + 1)]

    print(subset_sum(set, sum, len(set) - 1, dp))
