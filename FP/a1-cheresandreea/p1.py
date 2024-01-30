def f1():
    n = int(input("Give a number "))
    l = []
    while n > 0:
        l.append(n % 10)
        n = n // 10
    # print(l)
    l.sort()
    # print(l)
    m = 0
    for i in l:
        m = m * 10 + i
    return m


print(f1())
