class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        ret_val = strs[0]
        for i, c in enumerate(ret_val):
            for word in strs:
                if len(word) == i or word[i] != c:
                    return ret_val[:i]
        return ret_val
