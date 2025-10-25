#include <climits>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int solve(int k, vector<int> &coins) {
  if (k == 0) {
    return 0;
  }
  vector<int> memo(50000, -1);
  memo[0] = 0;

  for (int ki = 1; ki <= k; ki++) {
    int best = INT_MAX;
    for (int c : coins) {
      if (c <= ki && memo[ki-c] != -1 && memo[ki-c] != INT_MAX) {
        best = min(best, memo[ki - c] + 1);
      }
    }
    memo[ki] = best;
  }
  return memo[k];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> coins(n);
  for (auto &c : coins)
    cin >> c;

  int k;
  cin >> k;

  int res = solve(k, coins);

  cout << (res == INT_MAX ? -1 : res) << '\n';

  return 0;
}