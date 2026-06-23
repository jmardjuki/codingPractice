import math
import heapq


class Solution():
    @staticmethod
    def _haversine_helper( lat: float, long: float, qlat: float, qlong: float):
        # Convert to radians
        lat1 = math.radians(lat)
        lon1 = math.radians(long)
        lat2 = math.radians(qlat)
        lon2 = math.radians(qlong)

        # Deltas
        d_lat = lat1-lat2
        d_lon = lon1-lon2

        # Square of half the chord length between the points
        # a = sin²(Δlat/2) + cos(lat₁) · cos(lat₂) · sin²(Δlon/2)
        a = math.sin(d_lat / 2)**2 + math.cos(lat1) * math.cos(lat2) * math.sin(d_lon / 2)**2

        # Convert to angle
        # c = 2 · atan2(√a, √(1−a))
        c = 2* math.atan2(math.sqrt(a), math.sqrt(1-a))

        # Multiple Earth radius; R=6371
        # d = R · c
        d = 6371*c

        return d

    def kNearest(self, locations: List[List[float]], query_point: List[float], k: int) -> List[int]:
        heap = []
        # locations[i] = lat, lon
        for i, location in enumerate(locations):
            hv_val = self._haversine_helper(location[0], location[1], query_point[0], query_point[1])
            
            heapq.heappush(heap, (-hv_val, i))
            if len(heap) > k:
                heapq.heappop(heap)

        ret_list = list()

        for _ in range(k):
            val = heapq.heappop(heap)
            ret_list.insert(0, val[1])
        
        return ret_list

