def r(x1, y1, x2, y2, x3, y3):
    return x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2) > 0

while True:
    try:
        line = input()
    except:
        break

    x1, y1, x2, y2, x3, y3, xp, yp = map(float, line.strip().split())

    abc = r(x1, y1, x2, y2, x3, y3)
    pab = r(xp, yp, x1, y1, x2, y2)
    pbc = r(xp, yp, x2, y2, x3, y3)
    pca = r(xp, yp, x3, y3, x1, y1)

    print('YES' if abc == pab == pbc == pca else 'NO')
