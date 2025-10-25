#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> mem;
vector<vector<int>> choice;

int solve(int i, int capacity, vector<int> &weights, vector<int> &values) {
  if (i < 0 || capacity == 0)
    return 0;

  if (mem[i][capacity] != -1) {
    return mem[i][capacity];
  }

  int best = solve(i - 1, capacity, weights, values); // dont take
  choice[i][capacity] = 0;
  if (capacity >= weights[i]) { // take current
    int take = solve(i - 1, capacity - weights[i], weights, values) + values[i];
    if (take > best) {
      best = take;
      choice[i][capacity] = 1;
    }
  }

  mem[i][capacity] = best;
  return best;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, // capacity
      k; // stone count
  cin >> n >> k;

  mem = vector<vector<int>>(k, vector<int>(n + 1, -1));
  choice = vector<vector<int>>(k, vector<int>(n + 1, 0));

  vector<int> weights(k);
  vector<int> values(k);
  for (int i = 0; i < k; i++) {
    cin >> weights[i] >> values[i];
  }

  
  solve(k - 1, n, weights, values);

  vector<int> takeidx;
  int remaining = n;
  for (int i = k - 1; i >= 0; --i) {
    if (remaining >= 0 && choice[i][remaining]) {
      takeidx.push_back(i);
      remaining -= weights[i];
    }
  }
  sort(takeidx.begin(), takeidx.end());

  for (auto &idx : takeidx)
    cout << idx+1 << '\n';

  return 0;
}