class Solution:

  def is_palindrome(self, left: int, right: int) -> bool:
    if (left == right):
      return True
    if (right-left == 1):
      return self.s[left] == self.s[right]

    if self.dp[left][right] is not None:
      return self.dp[left][right]

    self.dp[left][right] = self.s[left] == self.s[right] and self.is_palindrome(left+1, right-1)
    return self.dp[left][right]

  def longestPalindrome(self, s: str) -> str:
    slen = len(s)
    if slen == 1:
      return s

    self.s = s
    self.dp = [[None] * slen for _ in range(slen)]

    for i in range(slen):
      self.dp[i][i] = True

    max_l = 0
    max_r = 0
    max_len = 1

    for l in range(0, len(s)):
      for r in range(l, len(s)):
        curlen = r-l+1
        if curlen <= max_len:
          continue

        if self.is_palindrome(l, r):
          max_len = curlen
          max_l = l
          max_r = r

    return s[max_l:max_r+1]

if __name__ == "__main__":
  s0 = "abbcccba"
  s1 = "cbbd"
  s2 = "aba"
  strs = ["abbcccba","cbbd","aba","borcdubqiupahpwjizjjbkncelfazeqynfbrnzuvbhjnyvrlkdyfyjjxnprfocrmisugizsgvhszooktdwhehojbrdbtgkiwkhpfjfcstwcajiuediebdhukqnroxbgtvottummbypokdljjvnthcbesoyigscekrqswdpalnjnhcnqrarxuufzzmkwizptyvjhpfidgmskuaggtpxqisdlyloznkarxofzeeyvteynluofuhbllyiszszbwnsglqjkignusarxsjvctpgiwnhdufmfpanfwxjwlmhgllzsmdpncbwnsbdtsvrjybynifywkulqnzprcxockbhrhvnwxrkvwumyieazclcviumvormynbryaziijpdinwatwqppamfiqfiojgwkvfzyxadyfjrgmtttvlgkqghgbcfhkigfojjkhskzenlpasyozcsuccdxhulcubsgomvcrbqwakrraesfifecmoztayrdjicypakrrneulfbqqxtrdelggedvloebqaztmfyfkhuonrognejxpesmwgnmnnnamvkxqvzrgzdqtvuhccryeowywmbixktnkqnwzlzfvloyqcageugmjqihyjxhssmhkfzxpzxmgpjgsduogfolnkkqizitbvvgrkczmojxnabruwwzxxqcevdwvtiigwckpxnnxxxdhxpgomncttjutrsvyrqcfwxhexhaguddkiesmfrqfjfdaqbkeqinwicphktffuwcazlmerdhraufbpcznbuipmymipxbsdhuesmcwnkdvilqbnkaglloswcpqzdggnhjdkkumfuzihilrpcvemwllicoqiugobhrwdxtoefynqmccamhdtxujfudbglmiwqklriolqfkknbmindxtljulnxhipsieyohnczddabrxzjmompbtnnxvivmoyfzfrxlufowtqzojfclmatthjtbhotdoheusnpirwicbtyrcuojsdmfcx"]
  for s in strs:
    print(Solution().longestPalindrome(s))
