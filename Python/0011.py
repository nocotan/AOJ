#!/usr/bin/env python
#-*- coding: utf-8 -*-

import sys

w = int(input())
n = int(input())

lst = range(1, w+1)

for num in sys.stdin:
    nums = num.split(",")
    a1 = int(nums[0]) - 1
    b1 = int(nums[1]) - 1

    a2 = lst[a1]
    b2 = lst[b1]
    lst[a1] = b2
    lst[b1] = a2

for i in lst:
    print(i)
