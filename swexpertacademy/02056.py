T = int(input())
for test_case in range(1,T+1):
    check = True
    date = input()
    year = date[0:4]
    month = date[4:6]
    day = date[6:8]
    rmonth = month
    rday = day
    month = int(month)
    day = int(day)
    if month<1 or month>12:
        check = False
    if month in [1,3,5,7,8,10,12] and (day<1 or day>31):
        check = False
    elif month==2 and (day<1 or day>28):
        check = False
    elif day<1 or day>30:
        check = False
    print(f'#{test_case}', end=' ')
    if(check):
        print(f'{year}/{rmonth}/{rday}')
    else:
        print('-1')