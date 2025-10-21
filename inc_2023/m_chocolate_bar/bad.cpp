// WHERE IT FAILS:
// 4 4 1
// 2 Cuts should be enough
// But since 1 isnt divisible by 2 or 4,
// The existing 2 cut checks don't catch it.
// EDGE CASE: cut twice, don't take any before second cut

#include <cstdio>

using namespace std;

typedef long long ll;

int calculate(ll w, ll h, ll area) {
  if (area > w * h) {
    return -1;
  }

  if (w * h == area) {
    return 0;
  }

  // mod w = split horizontal
  // mod h = split vertical
  if (area % w == 0 || area % h == 0) {
    return 1;
  }

  for (ll i = 1; i < w; i++) {
    ll left_rem = area - i * h;
    if (left_rem >= 0 && left_rem % (w - i) == 0) {
      return 2;
    }
  }

  for (ll i = 1; i < h; i++) {
    ll top_rem = area - w * i;
    if (top_rem >= 0 && top_rem % (h - i) == 0) {
      return 2;
    }
  }


  return 3;
}

int main() {
  ll n, m; // width, height
  ll k;     // area
  scanf("%lld %lld %lld", &n, &m, &k);

  printf("%d\n", calculate(n, m, k));
  return 0;
}
