# Problem 5. Longest Palindromic Substring

Given a string s, return the longest palindromic substring in s.

Example 1:

```
Input: s = "babad"
Output: "bab"
```

Explanation: "aba" is also a valid answer.

Example 2:

```
Input: s = "cbbd"
Output: "bb"
```

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.

# Solution & notes

## Top-Down DP

The problem can be solved using dynamic programming. We can create a 2D table where `dp[l][r]` will be `true` if the substring `s[l..r]` is a palindrome.

To fill this table, we can use the following rules:
- If `l == r`, then `dp[l][r]` is `true`
- If `s[l] == s[r]` and the **length of the substring is 2 or 3**, then `dp[l][r]` is `true`
- If `s[l] == s[r]` and `dp[l+1][r-1]` is `true`, then `dp[l][r]` is `true`

To actually fill the table we can just use brute force iteration over all possible substrings, checking the above conditions.
We can't purely use recursion because backtracking the (l, r) pairs is tricky.

## Bottom-Up "not so DP"

The solution I used may not be considered a pure dynamic programming solution, as it doesn't strictly follow the typical DP approach (we're not memoizing it). Instead, it employs a bottom-up method without memoization to save space.

From the top-down approach we know that we depend on a smaller substring (the center). So, we can iterate from center outwards (flood). This way we skip unnecessary checks and save space by not storing the entire DP table.