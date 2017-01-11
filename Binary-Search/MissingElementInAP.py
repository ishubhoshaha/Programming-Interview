'''
# Reference: http://www.geeksforgeeks.org/find-missing-number-arithmetic-progression/
# Time Complexity: 0(logn)
'''

def BinarySearch(lst):
    n = len(lst)
    start = 0
    ends = n-1
    difference = (lst[n-1]-lst[0])/n
    while(start<ends):
        mid = (start+ends)/2
        if abs(lst[mid]-lst[mid-1])!=difference:
            return lst[mid-1]+difference
        elif abs(lst[mid]-lst[mid+1])!=difference:
            return lst[mid]+difference
        elif (lst[start]+mid*difference) == lst[mid]:
            start = mid+1
        else:
            ends = mid-1

lst = [int(x) for x in raw_input().split()]
print BinarySearch(lst)
