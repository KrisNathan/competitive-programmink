// This is bad for handling the not found cases

#include <algorithm>
#include <iostream>
#include <climits>
#include <map>
#include <vector>

using namespace std;

vector<int> mem(50000, -1);
int solve(int k, vector<int> &coins) {
  if (k == 0) {
    return 0;
  }

  if (k < 0) {
    return INT_MAX;
  }

  if (mem[k] != -1) {
    return mem[k];
  }


  int best = INT_MAX;
  for (auto c : coins) {
    int res = solve(k - c, coins);
    if (res == INT_MAX)
      continue;

    best = min(best, res + 1);
  }
  mem[k] = best;
  return best;
}

int main() {
  int n;
  cin >> n;

  vector<int> coins(n);
  for (auto &c : coins) {
    cin >> c;
  }

  int k;
  cin >> k;

  int res = solve(k, coins);
  cout << ((res == INT_MAX) ? -1 : res) << '\n';

  return 0;
}