/*
This optimization is not effective.
Using string instead of list only reduces the need for pointer management.
However, the overall complexity remains the same.
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  string digits;
  for (int i = 0; i < n; i++) {
    cin >> digits;
    
    int turn = 0;

    if (digits.length() >= 3) {
      int idx = 2;
      while (idx < digits.length()) {
        int a = digits[idx - 2] - '0';
        int b = digits[idx - 1] - '0';
        int c = digits[idx] - '0';

        if ((a + b + c) % 3 == 0) {
          digits.erase(idx - 1, 1);
          if (idx >= 3) {
            idx--;
          }
          turn++;
        } else {
          idx++;
        }
      }
    }
    cout << (turn % 2 == 0 ? "Kamu" : "Anda") << "\n";
  }
  return 0;
}