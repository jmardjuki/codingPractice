class MedianFinder:

    def __init__(self):
        self.heapMin = []
        self.heapMax = []

    def addNum(self, num: int) -> None:
        heappush(self.heapMin, num)

        if self.heapMax and self.heapMin and (self.heapMin[0] < -self.heapMax[0]):
            heappush(self.heapMax, -heappop(self.heapMin))

        # Rebalance
        if len(self.heapMax) > len(self.heapMin):
            heappush(self.heapMin, -heappop(self.heapMax))
        # Rebalance
        if len(self.heapMin) > len(self.heapMax):
            heappush(self.heapMax, -heappop(self.heapMin))    

    def findMedian(self) -> float:
        count = len(self.heapMax) + len(self.heapMin)
        # If odd
        if count & 1:
            return -self.heapMax[0]
        else: # Even
            return (self.heapMin[0] + -self.heapMax[0])/2


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
