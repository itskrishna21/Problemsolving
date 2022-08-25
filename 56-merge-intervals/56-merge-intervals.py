class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        sorted_intervals = sorted(intervals, key = lambda interval: interval[0])
        res = []
        curr = sorted_intervals[0]
        
        for start, end in sorted_intervals[1: ]:
            if start <= curr[1]:
                curr = [curr[0], max(curr[1], end)]
            else:
                res.append(curr)
                curr = [start, end]
                
        res.append(curr)
        return res