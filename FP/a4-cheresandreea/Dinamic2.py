'''
Given the set of positive integers S, partition this set into two subsets
S1 and S2 so that the difference between the sum of the elements in S1 and
S2 is minimal. For example, for set S = { 1, 2, 3, 4, 5 }, the two subsets
could be S1 = { 1, 2, 4 } and S2 = { 3, 5 }. Display at least one of the solutions.
'''

import sys

def findMin(a, n, sum):
    # Create a 2d list to store
    # results of subproblems
    m = [[0 for i in range(0, sum + 1)]
          for j in range(0, n + 1)]
    # Initialize first column as true.
    # 0 sum is possible
    # with all elements.
    for i in range(0, n+1):
        m[i][0] = True
    # Initialize top row, except dp[0][0],
    # as false. With 0 elements, no other
    # sum except 0 is possible
    for j in range(1, sum + 1):
        m[0][j] = False
    # Fill the partition table in
    # bottom up manner
    for i in range(1, n + 1):
        for j in range(1, sum + 1):
            # If i'th element is excluded
            m[i][j] = m[i - 1][j]

            # If i'th element is included
            if a[i - 1] <= j:
                m[i][j] |= m[i - 1][j - a[i - 1]]
    # Initialize difference
    # of two sums with the maximum value
    dif = sys.maxsize
    #from sum//2 to 0 with the step -1
    for j in range(sum // 2, -1, -1):
        if m[n][j] == True:
            difin = sum - j
            dif = sum - (2 * j)
            break
    print(dif)
    '''
    a.reverse()
    s = 0
    x = []
    y = []
    for i in range(0, n):
        if(s < difin):
            x.append(a[i])
            s = s + a[i]
        else:
            y.append(a[i])
            s = s + a[i]
    
    print("{", end = " ")
    for i in range(0, len(x)):
        print(x[i], end = " ")
    print("}")
    print()
    print("{",end = " ")
    for i in range(0, len(y)):
        print(y[i], end = " ")
    print("}")
'''

def start():
    a = []
    sum = 0
    n = int(input("Da un numar: "))
    for i in range(0, n):
        ele = int(input())
        a.append(ele)
        sum = sum + ele
    a.sort()
    print("The minimun difference between 2 sets is ")
    findMin(a,n,sum)

start()