class Solution:

  def flood(self, left: int, right: int) -> tuple[int, int]:
    while left >= 0 and right < self.slen and self.s[left] == self.s[right]:
      left -= 1
      right += 1
    
    return (left+1, right-1)

  def longestPalindrome(self, s: str) -> str:
    self.slen = len(s)
    if self.slen == 1:
      return s
    self.s = s


    max_l = 0
    max_r = 0
    max_len = 1

    for i in range(0, self.slen):
      lodd, rodd = self.flood(i, i)
      lenodd = rodd-lodd+1
      if lenodd > max_len:
        max_len = lenodd
        max_l = lodd
        max_r = rodd

    for i in range(0, self.slen-1):
      leven, reven = self.flood(i, i+1)
      leneven = reven-leven+1
      if leneven > max_len:
        max_len = leneven
        max_l = leven
        max_r = reven

    return s[max_l:max_r+1]

if __name__ == "__main__":
  s0 = "abbcccba"
  s1 = "cbbd"
  s2 = "aba"
  strs = ["abbcccba","cbbd","aba","borcdubqiupahpwjizjjbkncelfazeqynfbrnzuvbhjnyvrlkdyfyjjxnprfocrmisugizsgvhszooktdwhehojbrdbtgkiwkhpfjfcstwcajiuediebdhukqnroxbgtvottummbypokdljjvnthcbesoyigscekrqswdpalnjnhcnqrarxuufzzmkwizptyvjhpfidgmskuaggtpxqisdlyloznkarxofzeeyvteynluofuhbllyiszszbwnsglqjkignusarxsjvctpgiwnhdufmfpanfwxjwlmhgllzsmdpncbwnsbdtsvrjybynifywkulqnzprcxockbhrhvnwxrkvwumyieazclcviumvormynbryaziijpdinwatwqppamfiqfiojgwkvfzyxadyfjrgmtttvlgkqghgbcfhkigfojjkhskzenlpasyozcsuccdxhulcubsgomvcrbqwakrraesfifecmoztayrdjicypakrrneulfbqqxtrdelggedvloebqaztmfyfkhuonrognejxpesmwgnmnnnamvkxqvzrgzdqtvuhccryeowywmbixktnkqnwzlzfvloyqcageugmjqihyjxhssmhkfzxpzxmgpjgsduogfolnkkqizitbvvgrkczmojxnabruwwzxxqcevdwvtiigwckpxnnxxxdhxpgomncttjutrsvyrqcfwxhexhaguddkiesmfrqfjfdaqbkeqinwicphktffuwcazlmerdhraufbpcznbuipmymipxbsdhuesmcwnkdvilqbnkaglloswcpqzdggnhjdkkumfuzihilrpcvemwllicoqiugobhrwdxtoefynqmccamhdtxujfudbglmiwqklriolqfkknbmindxtljulnxhipsieyohnczddabrxzjmompbtnnxvivmoyfzfrxlufowtqzojfclmatthjtbhotdoheusnpirwicbtyrcuojsdmfcx"]
  for s in strs:
    print(Solution().longestPalindrome(s))
