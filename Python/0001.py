hills = []
for i in range(10):
    hills.append(int(input()))

hills.sort()
hills.reverse()

for i in range(3):
    print(hills[i])
