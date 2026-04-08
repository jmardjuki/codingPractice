class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        tmp_array = []
        for point in points:
            dist = (point[0])**2 + (point[1])**2
            tmp_array.append((dist, point))

        sorted_data = sorted(tmp_array, key=lambda x: x[0])
        ret_list = []
        for i in range(k):
            ret_list.append(sorted_data[i][1])

        return ret_list
