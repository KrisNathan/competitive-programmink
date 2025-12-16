#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        vector<int> mem(n+1, 0);
        mem[0] = 1;
        mem[1] = 1;
        for (int i = 2; i <= n; i++) {
          mem[i] = mem[i-1] + mem[i-2];
        }
        return mem[n];
    }
};
