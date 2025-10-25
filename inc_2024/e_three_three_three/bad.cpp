/*
Why this fails:
Suppose first 3 digits arent divisible by 3, move on to next digit
Next digit is divisible by 3, remove middle digit

This implementation ignores the first digit still being usable again.

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

instead of 123 during turn (1), this implementation does:
23
ANDA wins

*/

#include <iostream>
#include <string>

using namespace std;

bool solve(string &num) {
  bool isAnda = true;
  bool isOver = false;

  int idx = 0;
  while (!isOver) {
    if (num.length() - idx < 3) {
      break; // current guy loses
    }

    // shit
    int a = num[idx] - '0';
    int b = num[idx + 1] - '0';
    int c = num[idx + 2] - '0';

    bool isDivisibleByThre = ((a + b + c) % 3 == 0);

    if (!isDivisibleByThre) {
      idx++;
      continue;
    }

    // pop mid later
    num[idx + 1] = a;
    idx++;

    isAnda = !isAnda;
  }

  return isAnda;
}

int main() {
  int n; // case counts
  cin >> n;

  string num;
  for (int i = 0; i < n; i++) {
    cin >> num;
    bool isAndaLose = solve(num);
    if (isAndaLose) {
      printf("Kamu\n");
    } else {
      printf("Anda\n");
    }
  }
  return 0;
}