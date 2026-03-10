/*
J
P

arr A[N]
start J

J:
select subarr [2:K] incl
replace with sum

P:
same
replace with bitwise XOR all subarr elem
if |X| = 2 -> X1 XOR X2
if |X| > 2 -> xor all

J wins if last elem % 2 == 1
P wins if last elem % 2 == 0
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, k;

  cin >> n >> k;

  vector<int> arr(n);
  for (auto &elem : arr) {
    cin >> elem;
  }

  int turn = 0;  // 0 for J, 1 for P
  vector<int> buffer;
  buffer.reserve(n);

  for (int i = 0; i < n; i++) {
    buffer.push_back(arr[i]);
    
    while (buffer.size() >= k) {
      vector<int> subarr(buffer.end() - k, buffer.end());
      buffer.erase(buffer.end() - k, buffer.end());

      int new_elem;
      if (turn == 0) {
        // J's turn: sum
        new_elem = 0;
        for (int val : subarr) {
          new_elem += val;
        }
      } else {
        // P's turn: bitwise XOR
        if (subarr.size() == 2) {
          new_elem = subarr[0] ^ subarr[1];
        } else {
          new_elem = subarr[0];
          for (size_t j = 1; j < subarr.size(); j++) {
            new_elem ^= subarr[j];
          }
        }
      }

      buffer.push_back(new_elem);
      turn = 1 - turn;
    }
  }

  int last_elem = buffer.back();
  cout << last_elem << '\n';
  if (last_elem % 2 == 1) {
    cout << "J wins" << '\n';
  } else {
    cout << "P wins" << '\n';
  }

  return 0;
}