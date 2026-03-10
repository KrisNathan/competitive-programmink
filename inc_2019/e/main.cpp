#include <iostream>
#include <vector>

typedef long long unsigned llu;

#define MOD 1000000007

using namespace std;

template<typename T>
struct SegmentTree {
  vector<T> tree;
  vector<T> arr;
  int n;

  
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  vector<llu> arr(n, 0);
  FenwickTree<llu> fenwick(arr);
  for (int i = 0; i < q; i++) {
    int type, l, r;
    cin >> type >> l >> r;
    l--; // convert to 0-based index
    r--;

    if (type == 1) {
      f(l, r, fenwick);
    } else if (type == 2) {
      cout << fenwick.sum(l, r) << "\n";
    }
  }

  return 0;
}