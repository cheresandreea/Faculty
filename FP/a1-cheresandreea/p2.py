# Solve the problem from the second set here
n = int(input("Give a number "))
x = y = 1
def fibo(x, y):
    ok = 0
    while ok == 0:
        z = x + y
        x = y
        y = z
        if z > n:
            ok = 1
    return z


m = fibo(x, y)
print(m)
