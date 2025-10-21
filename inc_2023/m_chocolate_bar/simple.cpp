#include <cstdio>

using namespace std;

typedef long long ll;

ll calculate(ll w, ll h, ll area) {
  if (w * h == area) {
    return 0;
  }

  // mod w = split horizontal
  // mod h = split vertical
  if (area % w == 0 || area % h == 0) {
    return 1;
  }

  // CASE: cut twice, take one before second cut
  for (int i = 1; i < w; i++) {
    ll left_rem = area - i * h;
    if (left_rem > 0 && left_rem % (w - i) == 0) {
      return 2;
    }
  }

  for (int i = 1; i < h; i++) {
    ll top_rem = area - w * i;
    if (top_rem > 0 && top_rem % (h - i) == 0) {
      return 2;
    }
  }

  // EDGE CASE: cut twice, don't take any before second cut
  for (int i = 1; i < w; i++) {
    if (area % i == 0) {
      ll n = area / i;
      if (n < h) {
        return 2;
      }
    }
  }

  return 3;
}

int main() {
  ll n, m; // width, height
  ll k;    // area
  scanf("%lld %lld %lld", &n, &m, &k);

  printf("%lld\n", calculate(n, m, k));
  return 0;
}
