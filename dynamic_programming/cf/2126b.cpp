#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> mem; // key is day, value is hike count
int solve(int day, int k, vector<int> &weathers) {
  if (day + k >= weathers.size()) {
    return 0;
  }

  if (mem[day] != -1) {
    return mem[day];
  }

  // don't hike
  int max_hike = solve(day + 1, k, weathers);

  bool can_hike = true;
  for (int i = 0; i < k; i++) {
    if (weathers[day + i] == 1) {
      can_hike = false;
      break;
    }
  }
  if (can_hike) {
    max_hike = max(max_hike, solve(day + k, k, weathers) + 1);
  }

  mem[day] = max_hike;

  return max_hike;
}

int solve2(vector<int> &weathers) {
  vector<int> m;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n, // arrsize
        k; // hike

    cin >> n >> k;

    mem.assign(100002, -1);

    vector<int> weathers(n);
    for (auto &w : weathers) {
      cin >> w;
    }

    int res = solve(0, k, weathers);
    cout << res << '\n';
  }

  return 0;
}