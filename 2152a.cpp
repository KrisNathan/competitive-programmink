#include <iostream>
#include <set>

/*
1 1 3 5
1 3 5

0 0 0
2 2 2
2 0 2
4 2 4
0 2 4
1 3 5

*/

using namespace std;

int main() {
  int t = 0;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;

    set<int> s;

    for (int j = 0; j < n; j++) {
      int a;
      cin >> a;
      s.insert(a);
    }

    cout << s.size() * 2 - 1 << '\n';
  }
  return 0;
}