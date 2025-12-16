class Solution {
public:
    int dp(int n, vector<int> &mem) {
        if (n == 0) return 1;
        if (n < 0) return 0;

        if (mem[n] != -1) return mem[n];

        return mem[n] = dp(n-1, mem) + dp(n-2, mem);
    }
    int climbStairs(int n) {
        vector<int> mem(n+1, -1);
        return dp(n, mem);
    }
};
