// Everything is 1-indexed (except strings themselves)

#include <cstdio>
#include <string>
#include <vector>

using namespace std;

typedef unsigned long long ull;

const ull base = 131ULL;
const ull mod = 1000000007ULL; // 1e9+7

class HashResult {
public:
  vector<ull> hashes;
  vector<ull> powers;

  HashResult(const vector<ull> &hashes, const vector<ull> &powers)
      : hashes(hashes), powers(powers) {}

  HashResult(const string &s, ull base, ull mod) {
    int len = (int)s.size();
    hashes = vector<ull>(len + 1, 0);
    powers = vector<ull>(len + 1, 1);

    for (int i = 1; i <= len; ++i) {
      powers[i] = (powers[i - 1] * base) % mod;
      hashes[i] = (hashes[i - 1] * base + (unsigned char)s[i - 1]) % mod;
    }
  }

  ull substring_hash(int l, int r, ull mod) const {
    if (l > r)
      return 0;
    return (hashes[r] + mod - (hashes[l - 1] * powers[r - l + 1]) % mod) % mod;
  }
};

/**
 * O(n)
 */
bool substring_search(string str, string query) {
  HashResult shr = HashResult(str, base, mod);
  HashResult qhr = HashResult(query, base, mod);

  bool found = false;
  for (int i = 1; i + query.length() - 1 <= str.length(); i++) {
    ull sub_hash = shr.substring_hash(i, i + query.length() - 1, mod);
    found = sub_hash == qhr.hashes[query.length()];
  }

  return found;
}

int main() {
  printf("is found? %d\n", substring_search("hello world", "world") ? 1 : 0);
  printf("is found? %d\n", substring_search("hello world", "llo") ? 1 : 0);
  printf("is found? %d\n", substring_search("hello world", "llow") ? 1 : 0);

  return 0;
}