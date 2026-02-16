class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        s_dict, t_dict = dict(), dict()

        # As we did this check, we now there is equal number
        #  of charcater in both
        if len(s) != len(t):
            return False

        # Length is equal, so can do at the same time
        for i in range(len(s)):
            s_dict[s[i]] =  1 + s_dict.get(s[i], 0)
            t_dict[t[i]] =  1 + t_dict.get(t[i], 0)
        
        for item in s_dict:
            if s_dict[item] != t_dict.get(item, 0):
                return False
        return True

