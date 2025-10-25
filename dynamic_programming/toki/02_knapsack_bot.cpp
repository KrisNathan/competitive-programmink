#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve(int cap, vector<int> &w, vector<int> &v) {
  vector<int> dp(cap + 1, 0);
  vector<vector<int>> items(cap + 1);

  for (int i = 1; i <= w.size(); i++) {     // i = item id
    for (int j = cap; j >= w[i - 1]; j--) { // j = cap
      if (dp[j - w[i - 1]] + v[i - 1] > dp[j]) {
        dp[j] = dp[j - w[i - 1]] + v[i - 1];
        items[j] = items[j - w[i - 1]];
        items[j].push_back(i);
      }
      // dp[j] = max(dp[j], dp[j - w[i - 1]] + v[i - 1]);
    }
  }

  for (auto it : items[cap]) {
    cout << it << '\n';
  }

  // return dp[cap];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n; // capacity
  int k; // stone count

  cin >> n >> k;

  vector<int> weights(k);
  vector<int> values(k);
  for (int i = 0; i < k; i++) {
    cin >> weights[i] >> values[i];
  }

  solve(n, weights, values);

  return 0;
}