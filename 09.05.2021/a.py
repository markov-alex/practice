from datetime import datetime

dates = [
    ('Aries', datetime(2020,3,21), datetime(2020,4,19)),
    ('Taurus', datetime(2020,4,20), datetime(2020,5,20)),
    ('Gemini', datetime(2020,5,21), datetime(2020,6,20)),
    ('Cancer', datetime(2020,6,21), datetime(2020,7,22)),
    ('Leo', datetime(2020,7,23), datetime(2020,8,22)),
    ('Virgo', datetime(2020,8,23), datetime(2020,9,22)),
    ('Libra', datetime(2020,9,23), datetime(2020,10,22)),
    ('Scorpio', datetime(2020,10,23), datetime(2020,11,22)),
    ('Sagittarius', datetime(2020,11,23), datetime(2020,12,21)),
    ('Capricorn', datetime(2020,12,22), datetime(2020,12,31)),
    ('Capricorn', datetime(2020,1,1), datetime(2020,1,19)),
    ('Aquarius', datetime(2020,1,20), datetime(2020,2,18)),
    ('Pisces', datetime(2020,2,19), datetime(2020,3,20)),
]

d = '2020' + input()[4:]
dt = datetime.strptime(d, '%Y-%m-%d')

for (name, start_dt, end_dt) in dates:
    if start_dt<=dt<=end_dt:
        print(name)
        break