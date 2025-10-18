#include <cstdio>
#include <string>
#include <vector>

using namespace std;

typedef unsigned long long ull;

struct HashResult {
  vector<ull> hashes;
  vector<ull> powers;
};

HashResult build_hash(string s, ull base, ull mod) {
  int len = (int)s.size();
  vector<ull> hashes(len + 1, 0);
  vector<ull> powers(len + 1, 1);

  for (int i = 1; i <= len; ++i) {
    powers[i] = (powers[i - 1] * base) % mod;
    hashes[i] = (hashes[i - 1] * base + (unsigned char)s[i - 1]) % mod;
  }

  return {hashes, powers};
}

ull substring_hash(int l, int r, ull mod, const vector<ull> &powers,
                   const vector<ull> &hashes) {
  if (l > r)
    return 0;
  return (hashes[r] + mod - (hashes[l - 1] * powers[r - l + 1]) % mod) % mod;
}

const ull base = 131ULL;
const ull mod = 1000000007ULL; // 1e9+7

/**
 * O(n)
 */
bool substring_search(string str, string query) {
  HashResult shr = build_hash(str, base, mod);
  HashResult qhr = build_hash(query, base, mod);

  bool found = false;
  for (int i = 1; i + query.length() - 1 <= str.length(); i++) {
    ull sub_hash =
        substring_hash(i, i + query.length() - 1, mod, shr.powers, shr.hashes);
    found = sub_hash == qhr.hashes[query.length()];
  }

  return found;
}

int main() {
  bool found = substring_search("hello world", "world");

  printf("is found? %d\n", found ? 1 : 0);

  return 0;
}