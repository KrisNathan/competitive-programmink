/*
Suppose first 3 digits arent divisible by 3, move on to next digit
Next digit is divisible by 3, remove middle digit
This now means the first digit is now usable again.

1243
ANDA (0):
124 -> not divisible
243 -> divisible, remove 4
KAMU (1):
123
123 -> divisible, remove 2
ANDA (2):
13
13 -> not divisible, no more digits
KAMU wins
*/

#include <cstdio>
#include <cstring>
#include <list>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  char str[100002];
  for (int i = 0; i < n; i++) {
    int turn = 0;
    scanf("%s", str);

    int len = 0;
    list<int> digits;
    for (char ch : str) {
      if (ch == '\0')
        break;
      digits.push_back(ch - '0');
      len++;
    }

    // 1 2 3 4 5
    // R234
    // 1245
    // R124 (handle)

    // 1 2 3 4 5 6 j=0
    // 2 3 4 5 6 j=1
    // 3 4 5 6 j=2
    // 4 5 6 j=3
    // 4 6 j = 2
    // 3 4 6

    if (len >= 3) {
      auto cursor = digits.begin();
      while (cursor != digits.end()) {
        auto first = cursor;
        auto second = next(first);
        if (second == digits.end()) {
          break;
        }

        auto third = next(second);
        if (third == digits.end()) {
          break;
        }

        int a = *first;
        int b = *second;
        int c = *third;

        if ((a + b + c) % 3 == 0) {
          digits.erase(second);
          turn++;
          cursor = (first == digits.begin()) ? first : prev(first);
        } else {
          advance(cursor, 1);
        }
      }
    }
    printf("%s\n", (turn % 2 == 0) ? "Kamu" : "Anda");
  }
}