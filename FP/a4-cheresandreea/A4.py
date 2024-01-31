'''
Consider the natural number n (n<=10) and the natural numbers a1, ..., an.
Determine all the possibilities to insert between all numbers a1, ..., an
the operators + and – such that by evaluating the expression the result is positive.
'''
'''
def afis(a, x, n):
    print(a[0],  end=' ')
    for i in range(1, n):
        if x[i] == 0:
            print("+", a[i],  end=' ') #we print + if we have 0 and - if we have 1
        else:
            print("-", a[i],  end=' ')
    print()

def isValid(k, a, x, n):
    if k == n - 1:
        s = 0
        for i in range (0, n):
            if x[i] == 0:
                s = s + a[i]
            else:
                s = s - a[i]
        if s < 0:
            return 0
    return 1

def isConsistent(k, a, x, n, sum):
    s=0
    for i in range(0,n):
        if x[i] == 0:
            s = s + a[i]
        else:
            s = s - a[i]
    s_final = sum - s
    if s_final+s > 0:
        return 1
    return 0

def back(k, a, x, n, sum): #we have
    for i in (0, 1): #we have 2 options 1/0
        x[k] = i #we try to give for the first element 0 and in the next steps 0 or 1
        if isValid(k, a, x, n) and isConsistent(k, a, x, n, sum): #we check if we have all n numbers and if the sum is positive
            if k == n - 1: #this is extra
                afis(a, x, n) #we print our list
            else:
                back(k + 1, a, x, n, sum) #if the conditions are not ok, we are going to the next elements


def start():
    a = [] #our future generated list
    x = [0,0,0,0,0,0,0,0,0,0] # our list of - and + -> we make our list 0 because otherwise it s not working
    n = int(input("Give a number: "))
    sum = 0
    for i in range(0, n): #we make our list
        ele = int(input())
        a.append(ele)
        sum=sum+ele

    back(1, a, x, n, sum)


start()
'''

'''
def afis(listb, listi, n): #listb = [[0,0,0,0], [0,0,0,1],..] listi = [3,4,5,6]

    #print(listb)
    for j in range(0, 2**n):
        listAct = listb[j]
        s = 0
        for i in range(0, n):
            if listAct[i] == 1:
                s = s - listi[i]
            else:
                s = s + listi[i]
        if s > 0:
            print(listAct)
            #print(listi[0], end=" ")
            for k in range(0, n):
                if listAct[k] == 1:
                    print("-", listi[k], end=" ")
                else:
                    print("+", listi[k], end=" ")
            print()
            print(s)
        ##print(listi[i])

def numarBaza2(x, n): #we are making lists with 0 and 1 
    list1 = []
    while x > 0:
        rest = x % 2
        list1.append(rest)
        x = x // 2
    a=len(list1)
    while(a < n):
        list1.append(0)
        a = a + 1

    list1.reverse()
    #print(list)
    return list1


def back(listi, n):
    listb = []
    for i in range(0, 2**n):
        lista = (numarBaza2(i, n))
        #print(lista)
        listb.append(lista) #we are making a list of lists with all the numbers in base 2

    afis(listb, listi, n)


def start():
    listi = []
    n = int(input("Da un numar: "))
    for i in range(0, n):
        ele = int(input())
        listi.append(ele)
    print("Our list: ", listi, '\n')

    back(listi, n)


#start()


'''

def afis(a, x, n):
    print(a[0], end = " ")
    for i in range(1, n):
        if x[i] == 0:
            print("+", a[i], end=" ")
        else:
            print("-", a[i], end = " " )
    print()

def isValid(a, x, n, k):
    if k == n - 1:
        s = 0
        for i in range(0, n):
            if x[i] == 0:
                s = s + a[i]
            else:
                s = s - a[i]
        if s < 0:
            return 0
        return 1

def isConsistent(k, a, x, n, sum):
    s=0
    for i in range(0,n):
        if x[i] == 0:
            s = s + a[i]
        else:
            s = s - a[i]
    s_final = sum - s
    if s_final+s > 0:
        return 1
    return 0

def back1(a, x, n, sum):
    k = 0
    while k > -1:
        if x[k] > -2:
            x[k] = x[k] + 1
            if isValid(a, x, n, k) and isConsistent(k, a, x, n, sum):
                k = k + 1
            else:
                x[k] = -1
                k = k - 1
        if k == n - 1:
            afis(a, x, n)
            k = k - 1
            
def back(a, x, n, sum):
    k = 0
    max = 1
    min = 0
    x[k] = min - 1
    while k > -1:
        if x[k] < max:
            x[k] = x[k] + 1
            if(isConsistent(k, a, x, n, sum)):
                if(isValid(a,x,n,k)):
                    afis(a,x,n)
                else:
                    k = k + 1
                    x[k] = min - 1
        else:
            k = k - 1



def start():
    a = []
    x = [0,0,0,0,0,0,0,0,0,0]
    n = int(input("Give a number: "))
    sum = 0
    for i in range(0, n):
        ele = int(input())
        a.append(ele)
        sum = sum + ele
    back(a, x, n, sum)

start()

