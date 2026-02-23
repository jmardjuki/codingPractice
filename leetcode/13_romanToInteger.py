class Solution:
    def romanToInt(self, s: str) -> int:
        roman_map = {
            'I' : 1,
            'V' : 5,
            'X' : 10,
            'L' : 50,
            'C' : 100,
            'D' : 500,
            'M' : 1000,
        }
        ret_val = 0
        prev_val = 0
        for c in reversed(s):
            curr_val = roman_map[c]
            if curr_val < prev_val:
                ret_val -= curr_val
            else:
                ret_val += curr_val

            prev_val = curr_val
        return ret_val
