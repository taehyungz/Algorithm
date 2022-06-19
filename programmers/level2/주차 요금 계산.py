from collections import defaultdict
import math

def solution(fees, records):
    def get_minutes(time):
        h, m = time.split(":")
        return 60 * int(h) + int(m)

    def calculate_fee(minutes):
        if minutes <= DEFAULT_TIME:
            return DEFAULT_FEE
        else:
            return DEFAULT_FEE + math.ceil((minutes - DEFAULT_TIME) / UNIT_TIME) * UNIT_FEE

    DEFAULT_TIME, DEFAULT_FEE, UNIT_TIME, UNIT_FEE = fees
    car_parked_time_map = defaultdict(int)
    car_in_time_map = defaultdict(int)

    for record in records:
        time, car_number, status = record.split()
        if status == "IN":
            car_in_time_map[car_number] = get_minutes(time)
        else:
            in_time = car_in_time_map[car_number]
            car_parked_time_map[car_number] += get_minutes(time) - in_time
            car_in_time_map.pop(car_number)

    for car_number, time in car_in_time_map.items():
        car_parked_time_map[car_number] += get_minutes("23:59") - time

    answer = list(map(lambda x: calculate_fee(x[1]),
                      sorted(car_parked_time_map.items())))
    return answer