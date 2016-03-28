import sys
import itertools

def func(n):
    count = 0
    for a, b, c, d in itertools.product(range(10), repeat=4):
        if a + b + c + d == n:
            count += 1
    return count

def main():
    for l in sys.stdin:
        n = int(l.strip())
        print(func(n))

if __name__ == '__main__':
    main()
