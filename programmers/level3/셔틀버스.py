from collections import defaultdict

def solution(n, t, m, timetable):
    def to_time(minutes):
        h = minutes // 60
        m = minutes - h * 60
        h = str(h) if h >= 10 else "0" + str(h)
        m = str(m) if m >= 10 else "0" + str(m)
        return h + ":" + m

    def to_minutes(time):
        h, m = time.split(":")
        return int(h) * 60 + int(m)

    def can_ride_cur_bus_at(time):
        return to_minutes("09:00") + (bus_cnt-1) * t >= to_minutes(time)

    def has_seat_on_cur_bus():
        return bus_seat_map[bus_cnt] > 0

    def can_ride_cur_bus(time):
        return can_ride_cur_bus_at(time) and has_seat_on_cur_bus()

    def get_cur_bus_depart_time():
        return to_time(to_minutes('09:00') + (bus_cnt-1) * t)

    # 9시부터 n회동안 t분마다 운행, 최대 m명 탑승
    # 버스 번호, 버스 남은 좌석 수
    bus_cnt, bus_seat_map = 1, dict(((i, m) for i in range(1, n+1)))
    timetable = sorted(timetable)
    idx = 0

    while idx < len(timetable):
        time = timetable[idx]
        # 현재 사람이 마지막 버스의 마지막 칸에 탔을 때
        if bus_cnt == n and not has_seat_on_cur_bus():
            return to_time(to_minutes(timetable[idx-1]) - 1)
        # 현재 사람이 자리가 남은 마지막 버스 시간보다 늦게 올 때
        elif bus_cnt == n and not can_ride_cur_bus_at(time):
            return get_cur_bus_depart_time()
        # 버스 탈 수 있고 여유공간 있을 때
        elif can_ride_cur_bus(time):
            bus_seat_map[bus_cnt] -= 1
            idx += 1
            # print(f"{idx}번째 사람({time}) 현재 버스: {bus_cnt}번 버스 {m-bus_seat_map[bus_cnt]}/{m} 출발시간: {get_cur_bus_depart_time()}")
        else:
            bus_cnt += 1

    if bus_cnt < n or has_seat_on_cur_bus():
        return to_time(to_minutes("09:00") + (n-1) * t)
    return to_time(to_minutes(timetable[idx-1]) - 1)