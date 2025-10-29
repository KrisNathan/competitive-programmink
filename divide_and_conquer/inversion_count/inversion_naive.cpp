/*
inversion: i < j; a[i] > a[j]
T(n) = 2T(n/2) + O(n^2)
O(n^2)
*/

#include <iostream>
#include <vector>

using namespace std;

int count = 0;
int runs = 0;
void inversion_merge(int l, int m, int r, vector<int> &a) {
  if (l == m) {
    if (a[l] > a[r]) {
      count++;
    }
    return;
  }

  // (n^2)/4
  // skip lg right
  for (int i = l; i <= m; i++) { // n/2
    // skip sm left
    for (int j = m + 1; j <= r; j++) { // n/2
      if (a[i] > a[j]) {
        count++;
      }
    }
  }
}

void inversion(int l, int r, vector<int> &a) {
  if (l >= r) {
    return;
  }

  int mid = l + (r - l) / 2;
  inversion(l, mid, a);
  inversion(mid + 1, r, a);

  inversion_merge(l, mid, r, a);
}

int inversion_init(vector<int> &a) {
  count = 0;
  inversion(0, a.size() - 1, a);
  return count;
}

int main() {
  vector<int> a = {6, 5, 1, 2, 3, 4};
  cout << inversion_init(a) << '\n';

  vector<int> b = {6, 5, 1, 2, 3, 7};
  cout << inversion_init(b) << '\n';

  vector<int> c = {6, 5, 4, 3, 2, 1};
  cout << inversion_init(c) << '\n';
  return 0;
}
