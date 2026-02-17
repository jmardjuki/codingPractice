class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        # Build reverse
        reverse = 0
        copy = x
        while(copy != 0):
            reverse = reverse*10 + copy%10
            copy = math.floor(copy/10)

        return reverse == x 
