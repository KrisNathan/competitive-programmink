#include <iostream>
#include <vector>
/*
3 if win
1 draw
0 lose

most point win

N matches

Ai > Bi = A pts += 3
Ai == Bi = A pts += 1
Ai < Bi = A pts += 0

determine total pts accumulated by A
*/

using namespace std;
int main() { 
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; // matches
  cin >> n;

  vector<int> A(n), B(n);
  for (auto &x : A) {
    cin >> x;
  }
  for (auto &x : B) {
    cin >> x;
  }

  int pts = 0;
  for (int i = 0; i < n; i++) {
    if (A[i] > B[i]) {
      pts += 3;
    } else if (A[i] == B[i]) {
      pts += 1;
    }
  }
  cout << pts << "\n";
  return 0;
}