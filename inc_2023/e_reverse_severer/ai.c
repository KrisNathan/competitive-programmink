#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define DEBUG 1
// We'll use double rolling hash (two moduli) for O(1) substring equality checks.
// Hash base and moduli
typedef unsigned long long ull;

const ull BASE1 = 1000003ULL;
const ull MOD1 = 1000000007ULL;
const ull BASE2 = 1000033ULL;
const ull MOD2 = 1000000009ULL;

// Compute prefix hashes for a string s of length n into arrays h1,h2 (1-indexed)
static void build_hashes(const char *s, int n, ull *h1, ull *h2, ull *p1,
                         ull *p2) {
  h1[0] = 0;
  h2[0] = 0;
  p1[0] = 1;
  p2[0] = 1;
  for (int i = 1; i <= n; ++i) {
    p1[i] = (p1[i - 1] * BASE1) % MOD1;
    p2[i] = (p2[i - 1] * BASE2) % MOD2;
    h1[i] = (h1[i - 1] * BASE1 + (unsigned char)s[i - 1]) % MOD1;
    h2[i] = (h2[i - 1] * BASE2 + (unsigned char)s[i - 1]) % MOD2;
  }
}

// Get hash of substring s[l..r] (1-indexed inclusive) using prefix hashes
static void get_sub_hash(const ull *h1, const ull *h2, const ull *p1,
                         const ull *p2, int l, int r, ull *out1, ull *out2) {
  ull x1 = (h1[r] + MOD1 - (h1[l - 1] * p1[r - l + 1]) % MOD1) % MOD1;
  ull x2 = (h2[r] + MOD2 - (h2[l - 1] * p2[r - l + 1]) % MOD2) % MOD2;
  *out1 = x1;
  *out2 = x2;
}

int main() {
  int len;
  char str[10002] = {};
  int query_count;
  scanf("%d %s %d", &len, str, &query_count);

  // Precompute hashes and powers for the original string `str`
  // Use 1-based arrays up to len
  ull *h1 = (ull *)malloc((len + 1) * sizeof(ull));
  ull *h2 = (ull *)malloc((len + 1) * sizeof(ull));
  ull *p1 = (ull *)malloc((len + 1) * sizeof(ull));
  ull *p2 = (ull *)malloc((len + 1) * sizeof(ull));
  if (!h1 || !h2 || !p1 || !p2) {
    fprintf(stderr, "Memory allocation failed\n");
    return 1;
  }
  build_hashes(str, len, h1, h2, p1, p2);

  char query[len + 1];
  for (int i = 0; i < query_count; i++) {
    if (scanf("%s", query) != 1) break;

    // build hashes for query
    ull *qh1 = (ull *)malloc((len + 1) * sizeof(ull));
    ull *qh2 = (ull *)malloc((len + 1) * sizeof(ull));
    ull *qp1 = (ull *)malloc((len + 1) * sizeof(ull));
    ull *qp2 = (ull *)malloc((len + 1) * sizeof(ull));
    if (!qh1 || !qh2 || !qp1 || !qp2) {
      fprintf(stderr, "Memory allocation failed\n");
      return 1;
    }
    build_hashes(query, len, qh1, qh2, qp1, qp2);

    int substr_start = 0;
    int substr_len = 1;
    int correct_count = 0;
    while (substr_start + substr_len <= len) {
      // compare query[substr_start .. substr_start+substr_len-1]
      // with str[len - substr_start - substr_len .. len - substr_start -1]
      int ql = substr_start + 1;
      int qr = substr_start + substr_len;
      int sl = len - substr_start - substr_len + 1;
      int sr = len - substr_start;

      ull qa1, qa2, sa1, sa2;
      get_sub_hash(qh1, qh2, qp1, qp2, ql, qr, &qa1, &qa2);
      get_sub_hash(h1, h2, p1, p2, sl, sr, &sa1, &sa2);

      if (qa1 == sa1 && qa2 == sa2) {
        correct_count += substr_len;
        substr_start += substr_len;
        substr_len = 1;
      } else {
        substr_len++;
      }
    }

#if (DEBUG)
    printf("Debug: correct_count = %d\n", correct_count);
#endif

    if (correct_count == len) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }

    free(qh1);
    free(qh2);
    free(qp1);
    free(qp2);
  }

  free(h1);
  free(h2);
  free(p1);
  free(p2);

  return 0;
}