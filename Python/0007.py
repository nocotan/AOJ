from math import ceil

yen = 100000
for i in range(int(input())):
    yen = ceil((yen*1.05)/1000)*1000
print(yen)
