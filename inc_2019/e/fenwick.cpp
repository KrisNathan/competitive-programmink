// time limit wtf

#include <iostream>
#include <vector>

using namespace std;

using ull = unsigned long long;
const ull MOD = 1'000'000'007ULL;

template <typename T> struct FenwickTree {
  vector<T> bit; // internal tree, 0‑based
  int n;

  explicit FenwickTree(int n) : bit(n, 0), n(n) {}

  explicit FenwickTree(const vector<T> &a) : FenwickTree((int)a.size()) {
    for (int i = 0; i < n; ++i) {
      add(i, a[i]);
    }
  }

  // adds delta to index idx
  void add(int idx, T delta) {
    delta %= MOD;
    while (idx < n) {
      bit[idx] += delta;
      if (bit[idx] >= MOD)
        bit[idx] -= MOD;
      idx |= idx + 1;
    }
  }

  // prefix sum on [0, r]
  T sum(int r) const {
    T ret = 0;
    while (r >= 0) {
      ret += bit[r];
      ret %= MOD;
      r = (r & (r + 1)) - 1;
    }
    return ret;
  }

  // sum on [l, r]
  T sum(int l, int r) const {
    if (l > r)
      return 0;
    T res = (sum(r) + MOD - sum(l - 1)) % MOD;
    return res;
  }
};

void f(int l, int r, FenwickTree<ull> &fenwick) {
  for (int k = l; k <= r; ++k) {
    ull left = (k - l + 1ULL) % MOD;
    ull right = (r - k + 1ULL) % MOD;
    ull delta = (left * right) % MOD;
    fenwick.add(k, delta);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  vector<ull> initial(n, 0);
  FenwickTree<ull> fenwick(initial);

  while (q--) {
    int type, l, r;
    cin >> type >> l >> r;
    --l;
    --r;

    if (type == 1) {
      f(l, r, fenwick);
    } else {
      cout << fenwick.sum(l, r) << '\n';
    }
  }

  return 0;
}