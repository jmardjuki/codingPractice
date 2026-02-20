class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        prev_dict = dict()

        for i in range(len(nums)):
            remain = target - nums[i]
            if remain in prev_dict:
                return [prev_dict[remain], i]
            # Save index
            prev_dict[nums[i]] = i

        
