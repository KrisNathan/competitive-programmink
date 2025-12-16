#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
  int longestPalindromeSubseq(string s) {
    int len = s.size();
    vector<vector<int>> mem(len + 1, vector<int>(len + 1, 0));

    for (int i = 0; i <= len; i++)
      mem[0][i] = 0;

    for (int l = 1; l <= len; l++) {
      for (int r = 1; r <= len; r++) {
        
      }
    }
  }
};

int main() {
  Solution s;
  cout << s.longestPalindromeSubseq("bbbab") << '\n';
  cout << s.longestPalindromeSubseq("cbbd") << '\n';
  cout << s.longestPalindromeSubseq("baa") << '\n';
  return 0;
}
