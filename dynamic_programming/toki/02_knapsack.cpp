#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct State {
  int w;
  int v;
  vector<int> items;
  bool computed = false;

  bool operator<(const State &r) {
    if (v != r.v)
      return v < r.v;
    if (w != r.w)
      return w > r.w;
    return items.size() < r.items.size();
  }
};

vector<vector<State>> mem;

State solve(int i, int capacity, vector<int> &weights, vector<int> &values) {
  if (i < 0 || capacity == 0)
    return {0, 0, {}, true};

  if (mem[i][capacity].computed) {
    return mem[i][capacity];
  }

  State best = solve(i - 1, capacity, weights, values); // dont take

  if (capacity >= weights[i]) { // take current
    State take = solve(i - 1, capacity - weights[i], weights, values);
    take.w += weights[i];
    take.v += values[i];
    take.items.push_back(i); // 0-indexed

    if (best < take) {
      best = take;
    }
  }

  mem[i][capacity] = best;
  mem[i][capacity].computed = true;
  return best;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, // capacity
      k; // stone count
  cin >> n >> k;

  mem = vector<vector<State>>(k, vector<State>(n + 1, {0, 0, {}}));

  vector<int> weights(k);
  vector<int> values(k);
  for (int i = 0; i < k; i++) {
    cin >> weights[i] >> values[i];
  }

  auto res = solve(k - 1, n, weights, values);

  // cout << res.v << '\n';

  sort(res.items.begin(), res.items.end());

  for (auto &idx : res.items)
    cout << idx + 1 << '\n'; // 1-indexed

  return 0;
}