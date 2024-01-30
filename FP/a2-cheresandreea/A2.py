import random

def InsertionSort(list, step):
    print("We have our list:", list)
    for i in range(1, len(list)):
        key = list[i]
        if i % step == 0:
            print("We are at step number ", i)
            print("We compare the key which is", key, " with the element ", list[i - 1],
                  "and if it is smaller, then we change key with it")
            print("We compare ", key,
                  " with each element on the left until an element is smaller than it, and then we put our element right before the smaller one.")
            print(list)
        j = i - 1
        while j >= 0 and key < list[j]:
            list[j + 1] = list[j]
            j = j - 1
        list[j + 1] = key
    print("The list of elements at the end of the assortment", list)


def GnomeSort(list, step):
    print("We have our list:", list)
    i = 0
    cont = 1
    ok = 0
    while i < len(list):

        if cont % step == 0:
            # print(list)
            print("We are at step number ", cont)
            print("We compare the current element which is", list[i], " with the element ", list[i - 1],
                  "and if it is smaller, we change the current element with it")
            if list[i] < list[i - 1]:
                print("We compare and switch", list[i],
                      " two by two with each element on the left until an element is smaller than it.")
            print(list)
            cont = cont + 1
    if i == 0:
        i = i + 1

    if list[i] >= list[i - 1]:
        # print("We are at step number ", cont)
        print("We have elements in the right order so we jump on the next element")
        print(list)
        i = i + 1
        # cont = cont + 1
    else:
        print("We have elements", list[i], "and", list[i - 1], "in the wrong order so we swap ", list[i], " with ",
              list[i - 1], list)
        list[i], list[i - 1] = list[i - 1], list[i]
        i = i - 1

    print("The list of elements at the end of the assortment", list)


def start():
    list = []
    while True:
        print("1.Generate random numbers ")
        print("2.Insert sort for our random numbers ")
        print("3.Gnome sort for our random numbers ")
        print("4.Show my list of numbers ")
        print("0.Exit")

        try:
            option = int(input("Select your option "))
        except:
            print("Invalid characters")
        else:
            if option == 1:
                try:
                    n = int(input("How many numbers do you want to generate? "))
                    list = []
                except:
                    print("Invalid characters")
                else:
                    for i in range(0, n):
                        number = random.randint(1, 100)
                        print(number)
                        list.append(number)

            elif option == 2 and len(list) == 0:
                print("There are no numbers in the list")
            elif option == 2:
                try:
                    step = int(input("Choose the step: "))
                except:
                    print("Invalid characters")
                else:
                    InsertionSort(list, step)
            elif option == 3 and len(list) == 0:
                print("There are no numbers in the list")
            elif option == 3:
                try:
                    step = int(input("Choose the step: "))
                except:
                    print("Invalid characters")
                else:
                    GnomeSort(list, step)
            elif option == 4:
                print(list)
            elif option == 0:
                break


start()
