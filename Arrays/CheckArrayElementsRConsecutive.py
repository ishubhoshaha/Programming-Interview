'''
    http://www.geeksforgeeks.org/check-if-array-elements-are-consecutive/
'''
def CheckConsecutiveOrNot(lst,n):
    for index in range(n-1):
        if(abs(lst[index]-lst[index+1])!=1):
            return False
    return True

n = int(raw_input())
lst = [int(x) for x in raw_input().split()]
if(CheckConsecutiveOrNot(sorted(lst),n)):
    print lst,
    print "is consecutive"
else:
    print lst,
    print "is not consecutive"