# Time Complexity: 0(m+n)

'''input
85 25 1 32 54 6
85 2
'''
from __future__ import print_function
import sys

def union():
    ans = []
    i, j = 0, 0
    for x in range(len(set1) + len(set2)):
        if i == len(set1):
            for index in range(j, len(set2)):
                ans.append(set2[index])
            break
        if j == len(set2):
            for index in range(i, len(set1)):
                ans.append(set1[index])
            break
        if (set1[i] < set2[j]):
            ans.append(set1[i])
            i += 1
        elif (set1[i] > set2[j]):
            ans.append(set2[j])
            j += 1
        else:
            ans.append(set1[i])
            i += 1
            j += 1
    return ans

def intersection():
    ans = []
    i, j = 0, 0
    for x in range(len(set1) + len(set2)):
        if i == len(set1):
            break
        if j == len(set2):
            break
        if (set1[i] < set2[j]):
            i += 1
        elif (set1[i] > set2[j]):
            j += 1
        else:
            ans.append(set1[i])
            i += 1
            j += 1
    return ans

set1 = map(int, raw_input().split())
set2 = map(int, raw_input().split())
print ("Union of set1 and set2 is ",sorted(union()))
print ("Intersection of set1 and set2 is ", sorted(intersection()))
