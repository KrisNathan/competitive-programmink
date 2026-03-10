#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long long ull;

// Compute prefix powers and prefix hashes for a string.
// hashes[i] = hash of prefix of length i (i.e. first i chars), hashes[0] = 0
void compute_prefix_hashes(const char *str, int len, ull base, ull mod, ull *powers, ull *hashes) {
  powers[0] = 1 % mod;
  hashes[0] = 0;
  for (int i = 1; i <= len; ++i) {
    powers[i] = (powers[i - 1] * base) % mod;
    // use unsigned char to avoid negative values for chars
    hashes[i] = (hashes[i - 1] * base + (unsigned char)str[i - 1]) % mod;
  }
}

/*
idx starts from 1
idx
1 2 3 4 5
str
a b c d e
  L   R

L = 2
R = 4
len = R-L+1 = 4-2+1 = 3

h[R] = ap^3 bp^2 cp^1 dp^0

We want: b c d; bp^2 cp^1 dp^0

OBJECTIVE: Get rid of a

We want to get rid of ap^3 from h[R]:

h[L-1] = a^0
h[L-1] * pow[len=3] = ap^0 p^3 = ap^3

h[R] = ap^3 bp^2 cp^1 dp^0
h[R] - h[L-1]*pow[len=3] = ?

This may cause underflowing, so we must slide the scope to the right using (mod):

h[R] + mod - h[L-1]*pow[len=3] = .. + ap^3 bp^2 cp^1 dp^0 - ap^3
= bp^2 cp^1 dp^0 


---
how: b2 c1 d0
R = a4 b3 c2 d1

R - [L-1] = b3 c2 d1
/bases[L] 

(hashes[R] - hashes[L-1])/bases[L]


*/

// Get hash of substring str[l..r] (0-based inclusive) using prefix hashes
ull substring_hash(int l, int r, ull mod, ull *powers, ull *hashes) {
  if (l > r) return 0;
  ull res = (hashes[r + 1] + mod - (hashes[l] * powers[r - l + 1]) % mod) % mod;
  return res; 
}

int main(void) {
  const char *str = "skibidi gyatt";
  int len = (int)strlen(str);

  const ull base = 131ULL;
  const ull mod = 1000000007ULL; // 1e9+7

  ull *powers = malloc((len + 1) * sizeof(ull));
  ull *hashes = malloc((len + 1) * sizeof(ull));
  if (!powers || !hashes) {
    fprintf(stderr, "allocation failed\n");
    return 2;
  }

  compute_prefix_hashes(str, len, base, mod, powers, hashes);

  const char *query = "gyatt";
  int qlen = (int)strlen(query);
  if (qlen == 0 || qlen > len) {
    printf("is found? 0\n");
    free(powers);
    free(hashes);
    return 0;
  }

  ull *qpowers = malloc((qlen + 1) * sizeof(ull));
  ull *qhashes = malloc((qlen + 1) * sizeof(ull));
  if (!qpowers || !qhashes) {
    fprintf(stderr, "allocation failed\n");
    free(powers);
    free(hashes);
    return 2;
  }

  compute_prefix_hashes(query, qlen, base, mod, qpowers, qhashes);
  ull qhash = substring_hash(0, qlen - 1, mod, qpowers, qhashes); // full query hash

  int found_index = -1;
  for (int i = 0; i + qlen - 1 < len; ++i) {
    ull sub = substring_hash(i, i + qlen - 1, mod, powers, hashes);
    if (sub == qhash) {
      found_index = i;
      break;
    }
  }

  printf("is found? %d\n", found_index != -1);
  if (found_index != -1) printf("index: %d\n", found_index);

  free(powers);
  free(hashes);
  free(qpowers);
  free(qhashes);
  return 0;
}