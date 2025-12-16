#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  int dp(string &s, int left, int right, vector<vector<int>> &mem) {
    if (left == right)
      return 1;
    if (left > right)
      return 0;

    if (mem[left][right] != -1)
      return mem[left][right];

    if (s[left] == s[right]) {
      return mem[left][right] = 2 + dp(s, left + 1, right - 1, mem);
    } else {
      return mem[left][right] =
                 max(dp(s, left + 1, right, mem), dp(s, left, right - 1, mem));
    }
  }

public:
  int longestPalindromeSubseq(string s) {
    int len = s.size();
    vector<vector<int>> mem(len + 1, vector<int>(len + 1, -1));
    return dp(s, 0, s.size() - 1, mem);
  }
};

int main() {
  Solution s;
  cout << s.longestPalindromeSubseq("bbbab") << '\n';
  cout << s.longestPalindromeSubseq("cbbd") << '\n';
  cout << s.longestPalindromeSubseq("baa") << '\n';
  return 0;
}
