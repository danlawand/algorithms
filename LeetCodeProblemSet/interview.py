#!/bin/python3

import math
import os
import random
import re
import sys



#
# Complete the 'findMaxHealthSum' function below.
#
# The function is expected to return a LONG_INTEGER.
# The function accepts following parameters:
#  1. INTEGER_ARRAY health
#  2. INTEGER_ARRAY serverType
#  3. INTEGER m
#

def findMaxHealthSum(health, serverType, m):
    a = []
    for i in range(len(health)):
        a.append((i, health[i], serverType[i]))
    
    b = sorted(a, key=lambda element: element[2], reverse=True)
    sT = [0]
    i = 0
    csT = b[0][2]
    for item in b:
        if csT != item[2]:
            sT.append(0)
            i += 1
            csT = item[2]
        sT[i] += item[1]
    sT = sorted(sT, reverse=True)
    ans = 0
    for i in range(0, min(m, len(sT))):
        ans += sT[i]
    return ans

def findLongestLength(fullString):
    n = len(fullString)
    if n <= 1:
        return 0

    i = 0
    p = False
    d = {}
    for c in fullString:
        if c not in d:
            d[c] = [i, -1]
        else :
            d[c][1] = i
            p = True
        i += 1
    print(d)

if __name__ == '__main__':
#     health = [2, 3, 1, 4]
#     serverType = [1, 1, 2, 2]
#     m = 4

#     # [1, 2, 3, 10, 10]
#     # [3, 3, 1, 2, 5]

#     # (1, 3) (2, 10) (3, 1) (3, 2) (5, 10)
# # st = 10, 10, 3, 3 
#     print(findMaxHealthSum(health, serverType, m))

    fullString = "amazonservices" # 11
    findLongestLength(fullString)
    fullString = "abadgdg" # 4
    fullString = "aaaaaaa" # 0


'''   d = {}
    for c in fullString:
        if c not in d:
            d[c] = 1
        else :
            d[c] += 1
    
    m = 0

    for s in range(n):
        v = True
        sub = {}
        for f in range(s, n):
            c = fullString[f]
            if c not in sub:
                sub[c] = 1
            else :
                sub[c] += 1
            if sub[c] > d[c]:
                v = False
                break
            if v and (f-s+1 < n):
                m = max(m, f-s+1)
    return m

if __name__ == '__main__':
#     health = [2, 3, 1, 4]
#     serverType = [1, 1, 2, 2]
#     m = 4

#     # [1, 2, 3, 10, 10]
#     # [3, 3, 1, 2, 5]

#     # (1, 3) (2, 10) (3, 1) (3, 2) (5, 10)
# # st = 10, 10, 3, 3 
#     print(findMaxHealthSum(health, serverType, m))

    fullString = "amazonservices" # 11
    print(findLongestLength(fullString))
    fullString = "abadgdg" # 4
    fullString = "aaaaaaa" # 0'''