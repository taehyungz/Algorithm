import heapq

def solution(m, musicinfos):
    def get_music(music):
        idx = 0
        ret = []
        while idx<len(music):
            if music[idx]!='#':
                ret.append(music[idx])
            else:
                ret[-1] = ret[-1].lower()
            idx += 1
        return ret
    
    answer = []
    for idx, mi in enumerate(musicinfos):
        stime, etime, title, music = mi.split(",")
        real_music = get_music(music) ##을 한 음으로 묶음
        stimes, etimes = stime.split(":"), etime.split(":")
        play_time = (int(etimes[0])-int(stimes[0]), int(etimes[1])-int(stimes[1]))
        running_time = play_time[0]*60 + play_time[1] #실제 플레이 시간(분)
        real_play = real_music*(running_time//len(real_music))+real_music[:running_time%len(real_music)] #실제 플레이 음악
        sreal_play = ''.join(real_play)
        converted_m = ''.join(get_music(m))
        
        if converted_m in sreal_play:
            print(converted_m, sreal_play)
            heapq.heappush(answer, (-running_time, idx, title))
    return heapq.heappop(answer)[2] if answer else "(None)"