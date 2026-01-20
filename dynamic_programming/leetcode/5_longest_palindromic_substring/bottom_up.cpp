#include <bits/stdc++.h>

using namespace std;

struct Result {
  int left;
  int right;
};

class Solution {
private:
  string &s = *(new string());
  int slen;

public:
  Result flood(int left, int right) {
    while (left >= 0 && right < slen && s[left] == s[right]) {
      left--;
      right++;
    }
    return {left + 1, right - 1};
  }

  string longestPalindrome(string s) {
    this->slen = s.length();
    if (this->slen == 1)
      return s;
    this->s = s;

    int max_l = 0;
    int max_r = 0;
    int max_len = 1;

    for (int i = 0; i < this->slen; i++) {
      // odd length palindrome
      {
        Result res = flood(i, i);
        int curr_len = res.right - res.left + 1;
        if (curr_len > max_len) {
          max_len = curr_len;
          max_l = res.left;
          max_r = res.right;
        }
      }

      // even length palindrome
      if (i + 1 < this->slen) {
        Result res = flood(i, i + 1);
        int curr_len = res.right - res.left + 1;
        if (curr_len > max_len) {
          max_len = curr_len;
          max_l = res.left;
          max_r = res.right;
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