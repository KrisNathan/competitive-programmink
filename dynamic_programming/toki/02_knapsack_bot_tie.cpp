// the correct solution.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct State {
  int w;
  int v;
  vector<int> items;

  bool operator<(const State &r) {
    if (v != r.v)
      return v < r.v;
    if (w != r.w)
      return w > r.w;
    return items.size() < r.items.size();
  }
};

void solve(int cap, vector<int> &w, vector<int> &v) {
  vector<State> dp(cap + 1, {0, 0, {}});

  for (int i = 1; i <= w.size() - 1; i++) { // i = item id (1-indexed)
    for (int j = cap; j >= w[i]; j--) {     // j = capacity
      State candidate = dp[j - w[i]];
      candidate.w += w[i];
      candidate.v += v[i];
      candidate.items.push_back(i);

      if (dp[j] < candidate) {
        dp[j] = candidate;
      }
    }
  }

  sort(dp[cap].items.begin(), dp[cap].items.end());

  for (auto it : dp[cap].items) {
    cout << it << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n; // capacity
  int k; // stone count

  cin >> n >> k;

  vector<int> weights(k + 1);
  vector<int> values(k + 1);
  for (int i = 1; i <= k; i++) {
    cin >> weights[i] >> values[i];
  }

  solve(n, weights, values);

  return 0;
}