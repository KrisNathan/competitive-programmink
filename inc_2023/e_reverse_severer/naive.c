#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define DEBUG 0

bool cmp_substr(char *stra, int lena, char *strb, int lenb) {
#if (DEBUG)
  printf("Debug: Comparing %.*s and %.*s\n", lena, stra, lenb, strb);
#endif

  if (lena != lenb) {
    return false;
  }
  for (int i = 0; i < lena; i++) {
    if (stra[i] != strb[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  int len;
  char str[10002] = {};
  int query_count;
  scanf("%d %s %d", &len, str, &query_count);

  char query[len];
  for (int i = 0; i < query_count; i++) {
    scanf("%s", query);

    int substr_start = 0;
    int substr_len = 1;
    int correct_count = 0;
    while (substr_start + substr_len <= len) {
      bool is_exist =
          cmp_substr(&query[substr_start], substr_len,
                     &str[len - substr_start - substr_len], substr_len);

      if (is_exist) {
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
  }

  return 0;
}