from sortedcontainers import SortedList
class Solution:
    
    def maximumRobots(self, chargeTimes: List[int], runningCosts: List[int], budget: int) -> int:
       
        
        mono_queue = SortedList()
        
        left = 0
        right = 0
        
        ans = 0
        
        s = 0
        
        curr = 0
        
        while right < len(chargeTimes):
            
            s += runningCosts[right]
            
            mono_queue.add(chargeTimes[right])
            
            curr = mono_queue[-1] + (right - left + 1) * s
            
            
            while len(mono_queue) > 0 and curr > budget:
                
                s -= runningCosts[left]
                
                mono_queue.remove(chargeTimes[left])
                
                if len(mono_queue) > 0:
                    curr = mono_queue[-1] + (right - left + 1) * s
                
                left += 1
                
            ans = max(ans, right - left + 1)
            
            right += 1
            
            
        return ans
        