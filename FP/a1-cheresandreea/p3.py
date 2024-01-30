# Solve the problem from the third set here
n = int(input("Give a number "))

def prime(d, i):
    if d < 2:
        return 0
    while (i * i <= d):
        if d % i == 0:
            return 0
        i = i + 1
    return 1

i = 1
while (n > 0):
    # print("nr n e acum", n)
    if prime(i, 2) == 1 or i == 1:
        # print(i)
        n = n - 1
        if n == 0:
            numar = i
    else:
        for divizor in range(2, i):
            if i % divizor == 0 and prime(divizor, 2) == 1:
                cont = divizor
                while (cont > 0):
                    # print(divizor)
                    cont = cont - 1
                    n = n - 1
                    if n == 0:
                        numar = divizor

    i = i + 1

print(numar)
