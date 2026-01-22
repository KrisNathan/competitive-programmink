from typing import List
from functools import cache

class Solution:
    sequence: str
    word: str
    dp: List[int]
    slen: int
    wlen: int

    @cache
    def rec(self, cursor: int):
        if cursor + self.wlen > self.slen:
            return 0

        if self.sequence[cursor : cursor + self.wlen] != self.word:
            return 0

        return 1 + self.rec(cursor + self.wlen)

    def maxRepeating(self, sequence: str, word: str) -> int:
        self.sequence = sequence
        self.word = word
        self.slen = len(sequence)
        self.wlen = len(word)

        maxlen = 0
        for i in range(self.slen):
            maxlen = max(maxlen, self.rec(i))

        return maxlen

if __name__ == '__main__':
    seq = 'aaabaaaabaaabaaaabaaaabaaaabaaaaba'
    word = 'aaaba'
    print(Solution().maxRepeating(seq, word)) # should be 5 according to leetcode