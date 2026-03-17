from typing import List

class Solution:
    def triangleType(self, nums: List[int]) -> str:
        a, b, c = nums
        if a + b <= c or b + c <= a or a + c <= b:
            return "none"
        if a == b == c:
            return "equilateral"
        elif a == b or b == c or a == c:
            return "isosceles"
        else:
            return "scalene"
