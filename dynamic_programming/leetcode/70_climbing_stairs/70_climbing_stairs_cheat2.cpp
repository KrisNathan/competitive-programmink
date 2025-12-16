#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        int a = 1;
        int b = 1;
        int temp;
        for (int i = 2; i <= n; i++) {
            temp = b;
            b = temp + a;
            a = temp;
        }
        return b;
    }
};
