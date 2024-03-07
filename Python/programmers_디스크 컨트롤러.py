import heapq
import math

def solution(jobs):
    answer = 0
    time = 0
    heap = []
    n = len(jobs)
    
    jobs.sort(key=lambda x:x[0])
    
    while len(jobs) > 0 or len(heap) > 0:
        while len(jobs) > 0 and jobs[0][0] <= time: 
            job = jobs.pop(0)
            heapq.heappush(heap, [job[1], job[0]])
    
        if len(heap) > 0:
            cur = heapq.heappop(heap)
            if time < cur[1]:
                time = cur[1]
            answer += (time - cur[1]) + cur[0]
            time += cur[0]
        else:
            time += 1
    
    return math.floor(answer / n)