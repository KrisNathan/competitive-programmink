#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int dp(int i, int n, vector<int>& cost, vector<int>& mem) {
        if (i >= n) return 0;
        if (mem[i] != -1) return mem[i];
        
        return mem[i] = min(
            dp(i+1, n, cost, mem), 
            dp(i+2, n, cost, mem)) + cost[i];
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> mem(cost.size() + 1, -1);
        return min(
            dp(0, cost.size(), cost, mem), 
            dp(1, cost.size(), cost, mem));
    }
};
