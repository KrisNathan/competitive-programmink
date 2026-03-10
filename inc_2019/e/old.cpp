#include <iostream>
#include <vector>

typedef long long unsigned llu;

#define MOD 1000000007

using namespace std;

// void f(int l, int r, vector<llu> &arr) {
//   for (int i = l; i <= r; i++) {
//     for (int j = i; j <= r; j++) {
//       for (int k = i; k <= j; k++) {
//         arr[k]++;
//       }
//     }
//   }
// }

void f(int l, int r, vector<llu> &arr) {
  for (int k = l; k <= r; ++k) {
    llu left = k - l + 1;   // ways to choose i
    llu right = r - k + 1;  // ways to choose j
    arr[k] += left * right; // update arr[k]
  }
}

llu sum_func(int l, int r, vector<llu> &arr) {
  llu sum = 0;
  for (int i = l; i <= r; i++) {
    sum = (sum + arr[i]) % MOD;
  }
  return sum;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  vector<llu> arr(n, 0);
  for (int i = 0; i < q; i++) {
    int type, l, r;
    cin >> type >> l >> r;
    l--; // convert to 0-based index
    r--;

    if (type == 1) {
      f(l, r, arr);
    } else if (type == 2) {
      llu res = sum_func(l, r, arr);
      cout << res << "\n";
    }
  }

  return 0;
}