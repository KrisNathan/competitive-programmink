/*
inversion: i < j; a[i] > a[j]
T(n) = 2T(n/2) + O(n)
O(n log n)

We are definitely trading for space complexity. (temp left and right arrays)
*/

#include <iostream>
#include <vector>

using namespace std;

int count = 0;

void merge(int l, int m, int r, vector<int> &a) {
  vector<int> left(a.begin() + l, a.begin() + m + 1);
  vector<int> right(a.begin() + m + 1, a.begin() + r + 1);

  int i = 0, j = 0, k = l;
  // n
  while (i < left.size() && j < right.size()) {
    if (left[i] <= right[j]) {
      a[k++] = left[i++];
    } else {
      a[k++] = right[j++];
      count +=
          left.size() - i; // surely all thats in left is greater than right[j]
    }
  }
  // sorting prepares for 'next' merge
  // n
  while (i < left.size()) {
    a[k++] = left[i++];
  }
  while (j < right.size()) {
    a[k++] = right[j++];
  }
}

void inversion(int l, int r, vector<int> &a) {
  if (l >= r) {
    return;
  }

  int m = l + (r - l) / 2;
  inversion(l, m, a);
  inversion(m + 1, r, a);
  merge(l, m, r, a);
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
