from typing import List

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows == 1:
            return [[1]]
        if numRows == 2:
            return [[1], [1,1]]

        pascal = [[1], [1,1]]
        for i in range(2, numRows):
            newline = [1]
            for j in range(1, i):
                newline.append(pascal[i-1][j-1] + pascal[i-1][j])
            newline.append(1)
            pascal.append(newline)
            # print(pascal)
        
        return pascal


#      1
#     1 1
#    1 2 1
#   1 3 3 1
#  1 4 6 4 1
# 1 5 10 10 5 1
