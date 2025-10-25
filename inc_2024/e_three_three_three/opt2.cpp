/*
This optimization is effective.

By using a stack-like buffer to store the digits, we can avoid the overhead of erase's content shifting.

The stack ensures that the item to be removed is at [bufLen - 2], allowing for O(1) removal by simply adjusting bufLen.

If you used vector instead of array for this, calling .erase would only shift element [bufLen-1], which is still very good O(1).
*/

#include <cstdio>
#include <cstring>

int main() {
  int n;
  scanf("%d", &n);

  char str[100002];
  for (int i = 0; i < n; i++) {
    int turn = 0;
    scanf("%s", str);

    int j = 0;
    char c = str[0];

    char buffer[100002] = {};
    int bufLen = 0;
    while (c != '\0') {
      buffer[bufLen++] = c;
      c = str[++j];

      while (2 < bufLen) {
        int a = buffer[bufLen - 3] - '0';
        int b = buffer[bufLen - 2] - '0';
        int c = buffer[bufLen - 1] - '0';

        if ((a + b + c) % 3 == 0) {
          // remove middle
          buffer[bufLen - 2] = buffer[bufLen - 1];
          bufLen--;
          turn++;
        } else {
          break;
        }
      }
    }
    printf("%s\n", (turn % 2 == 0 ? "Kamu" : "Anda"));
  }
  return 0;
}