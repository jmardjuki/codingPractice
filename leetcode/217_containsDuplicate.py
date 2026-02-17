class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        no_dup_set = set()
        for num in nums:
            if num in no_dup_set:
                return True
            no_dup_set.add(num)
        return False
