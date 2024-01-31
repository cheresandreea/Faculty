'''
Given the set of positive integers S, partition this set into two subsets
S1 and S2 so that the difference between the sum of the elements in S1 and
S2 is minimal. For example, for set S = { 1, 2, 3, 4, 5 }, the two subsets
could be S1 = { 1, 2, 4 } and S2 = { 3, 5 }. Display at least one of the solutions.
'''


def findMinRec(a, i, sumCalculated, sumTotal):
    if (i == 0):
        return abs((sumTotal - sumCalculated) - sumCalculated)

    return min(findMinRec(a, i - 1, sumCalculated + a[i - 1], sumTotal), findMinRec(a, i - 1, sumCalculated, sumTotal))

def findMin(a, n):
    sumTotal = 0
    for i in range(n):
        sumTotal += a[i]
    return findMinRec(a, n, 0, sumTotal)

#################################################################################################

def findMin2(a, n):
   a.sort()
   a.reverse()
   sum1 = sum2 = 0
   x = []
   y = []
   nrx = nry = 0
   for i in range(0, n):
       if (sum1 <= sum2):
            sum1 += a[i]
            x.append(a[i])
            nrx += 1
       else:
            sum2 += a[i]
            y.append(a[i])
            nry += 1

   for i in range(0, nrx):
       print(x[i], end = " ")
   print()
   for i in range(0, nry):
       print(y[i], end = " ")
   print()
   print(abs(sum1 - sum2))

def start():
    a = []
    n = int(input("Da un numar: "))
    for i in range(0, n):
        ele = int(input())
        a.append(ele)
    #print("The minimum difference " + "between two sets is ", findMin(a, n))
    findMin2(a,n)

start()
