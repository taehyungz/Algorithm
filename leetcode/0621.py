class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        counter = collections.Counter(tasks)
        time = 0
        
        while True:
            sub_count = 0
            
            for task, _ in counter.most_common(n+1):
                sub_count += 1
                time += 1
                
                counter[task] -= 1
                print(time, task)
                
                if counter[task]==0: del(counter[task]) # 0이하 아이템을 제거
                
            if not counter:
                break
            
            time += n-sub_count+1 # idle시간
        return time