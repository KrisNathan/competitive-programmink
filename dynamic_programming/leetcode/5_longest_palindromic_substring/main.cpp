#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
  string &s = *(new string());
  vector<vector<char>> dp;

public:
  char is_palindrome(int l, int r) {
    if (l == r)
      return 1;
    if (r - l == 1)
      return s[l] == s[r];

    if (this->dp[l][r] != -1)
      return this->dp[l][r];

    this->dp[l][r] = (s[l] == s[r]) && is_palindrome(l + 1, r - 1);
    return this->dp[l][r];
  }
  string longestPalindrome(string s) {
    int slen = s.length();

    if (slen == 1)
      return s;

    this->s = s;
    this->dp = vector<vector<char>>(slen, vector<char>(slen, -1));

    int max_l = 0;
    int max_r = 0;
    int max_len = 1;

    for (int l = 0; l < slen; l++) {
      for (int r = l; r < slen; r++) {
        int curr_len = r - l + 1;
        if (curr_len <= max_len)
          continue;

        if (is_palindrome(l, r)) {
          if (curr_len > max_len) {
            max_len = curr_len;
            max_l = l;
            max_r = r;
          }
        }
      }
    }
    return s.substr(max_l, max_len);
  }
};

int main() {
  Solution sol;
  string strs[] = {
      "abbcccba", "cbbd", "aba",
      "borcdubqiupahpwjizjjbkncelfazeqynfbrnzuvbhjnyvrlkdyfyjjxnprfocrmisugizsg"
      "vhszooktdwhehojbrdbtgkiwkhpfjfcstwcajiuediebdhukqnroxbgtvottummbypokdljj"
      "vnthcbesoyigscekrqswdpalnjnhcnqrarxuufzzmkwizptyvjhpfidgmskuaggtpxqisdly"
      "loznkarxofzeeyvteynluofuhbllyiszszbwnsglqjkignusarxsjvctpgiwnhdufmfpanfw"
      "xjwlmhgllzsmdpncbwnsbdtsvrjybynifywkulqnzprcxockbhrhvnwxrkvwumyieazclcvi"
      "umvormynbryaziijpdinwatwqppamfiqfiojgwkvfzyxadyfjrgmtttvlgkqghgbcfhkigfo"
      "jjkhskzenlpasyozcsuccdxhulcubsgomvcrbqwakrraesfifecmoztayrdjicypakrrneul"
      "fbqqxtrdelggedvloebqaztmfyfkhuonrognejxpesmwgnmnnnamvkxqvzrgzdqtvuhccrye"
      "owywmbixktnkqnwzlzfvloyqcageugmjqihyjxhssmhkfzxpzxmgpjgsduogfolnkkqizitb"
      "vvgrkczmojxnabruwwzxxqcevdwvtiigwckpxnnxxxdhxpgomncttjutrsvyrqcfwxhexhag"
      "uddkiesmfrqfjfdaqbkeqinwicphktffuwcazlmerdhraufbpcznbuipmymipxbsdhuesmcw"
      "nkdvilqbnkaglloswcpqzdggnhjdkkumfuzihilrpcvemwllicoqiugobhrwdxtoefynqmcc"
      "amhdtxujfudbglmiwqklriolqfkknbmindxtljulnxhipsieyohnczddabrxzjmompbtnnxv"
      "ivmoyfzfrxlufowtqzojfclmatthjtbhotdoheusnpirwicbtyrcuojsdmfcx"};

  for (auto &str : strs) {
    cout << "Input: " << str << endl;
    cout << "Output: " << sol.longestPalindrome(str) << endl;
    cout << "---------------------" << endl;
  }

  return 0;
}