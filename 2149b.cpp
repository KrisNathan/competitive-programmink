/*
1 2 3 4
1 3 -> i = 2
2 4

n = 6
1 2 3 4 5 6
1 4 -> i = 3 = n/2
2 5
3 6
*/

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (auto &v : arr) {
      cin >> v;
    }

    sort(arr.begin(), arr.end());

    int max_diff = 0;
    for (int i = 1; i < n; i += 2) {
      int diff = abs(arr[i] - arr[i - 1]);
      if (diff > max_diff) {
        max_diff = diff;
      }
    }

    int max_diff2 = 0;
    for (int i = 1; i + 1 < n; i += 2) {
      int diff = abs(arr[i + 1] - arr[i]);
      if (diff > max_diff2) {
        max_diff2 = diff;
      }
    }

    cout << min(max_diff, max_diff2) << '\n';
  }
  return 0;
}