#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 0

typedef unsigned long long ull;

const ull BASE1 = 131;
const ull BASE2 = 137;
const ull MOD1 = 1e9 + 7;
const ull MOD2 = 1e9 + 37;

// 1-indexed
typedef struct hash_result {
  ull *p1;
  ull *h1;
  ull *p2;
  ull *h2;
} HashResult;

void free_hr(HashResult* hr) {
  free(hr->h1);
  free(hr->h2);
  free(hr->p1);
  free(hr->p2);
}

// 1-indexed
HashResult hash(char *str, int len) {
  HashResult hr;
  hr.p1 = (ull *)malloc((len + 1) * sizeof(ull));
  hr.h1 = (ull *)malloc((len + 1) * sizeof(ull));
  hr.p2 = (ull *)malloc((len + 1) * sizeof(ull));
  hr.h2 = (ull *)malloc((len + 1) * sizeof(ull));

  hr.p1[0] = 1;
  hr.h1[0] = 0;
  hr.p2[0] = 1;
  hr.h2[0] = 0;

  for (int i = 1; i <= len; i++) {
    hr.p1[i] = (hr.p1[i - 1] * BASE1) % MOD1;
    hr.h1[i] = (hr.h1[i - 1] * BASE1 + (unsigned char)str[i - 1]) % MOD1;
    hr.p2[i] = (hr.p2[i - 1] * BASE2) % MOD2;
    hr.h2[i] = (hr.h2[i - 1] * BASE2 + (unsigned char)str[i - 1]) % MOD2;
  }

  return hr;
}

typedef struct hash_pair {
  ull h1;
  ull h2;
} HashPair;

// 1-indexed
HashPair substring_hash(const int l, const int r, const HashResult *hr) {
  HashPair hp;
  hp.h1 =
      (hr->h1[r] + MOD1 - (hr->h1[l - 1] * hr->p1[r - l + 1]) % MOD1) % MOD1;
  hp.h2 =
      (hr->h2[r] + MOD2 - (hr->h2[l - 1] * hr->p2[r - l + 1]) % MOD2) % MOD2;
  return hp;
}

// 0-indexed
bool cmp_substr(int a_start, int a_len, int b_start, int b_len,
                HashResult *a_hr, HashResult *b_hr) {
#if (DEBUG)
  printf("Debug: Comparing %.*s and %.*s\n", lena, stra, lenb, strb);
#endif

  if (a_len != b_len) {
    return false;
  }

  HashPair a_hash = substring_hash(a_start + 1, a_start + a_len, a_hr);
  HashPair b_hash = substring_hash(b_start + 1, b_start + b_len, b_hr);

  return a_hash.h1 == b_hash.h1 && a_hash.h2 == b_hash.h2;
}

int main() {
  int len;
  char str[10002] = {};
  int query_count;
  scanf("%d %s %d", &len, str, &query_count);

  HashResult string_hash = hash(str, len);

  char query[10002] = {};
  for (int i = 0; i < query_count; i++) {
    scanf("%s", query);

    HashResult query_hash = hash(query, len);

    int substr_start = 0;
    int substr_len = 1;
    int correct_count = 0;
    while (substr_start + substr_len <= len) {
      bool is_exist =
          cmp_substr(substr_start, substr_len, len - substr_start - substr_len,
                     substr_len, &query_hash, &string_hash);

      if (is_exist) {
        correct_count += substr_len;
        substr_start += substr_len;
        substr_len = 1;
      } else {
        substr_len++;
      }
    }

    free_hr(&query_hash);

#if (DEBUG)
    printf("Debug: correct_count = %d\n", correct_count);
#endif

    if (correct_count == len) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }

  free_hr(&string_hash);

  return 0;
}