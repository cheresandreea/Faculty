import datetime
import random
from random import choice
from random import randint

from test.reservation import Reservation


def load_1():
    l = []
    with open("room_number.txt", "r") as f:
        for i in f.readlines():
            l.append(i)
    return l

def load_2():
    l = []
    with open("room_type.txt", "r") as f:
        for i in f.readlines():
            l.append(i)

    return l

def save_3(l):
    with open("generation.txt", "w") as f:
        for i in l:
            f.write(i.number + " " + i.room_type + " " + i.name  + " " +str(i.arrival) + " " + str(i.departure) + '\n')


def gen():
    fam_name = ["Bob", "Man", "Coman", "Alb", "Dei"]
    first_name = ["Marius", "Adrian", "Anda", "Carmen", "Paul"]
    list1 = load_1()
    list2 = load_2()
    l = []
    for i in range(0, 1000):
        numb = str(random.randint(0,100)) + random.choice(list1)
        type = random.choice(list2)
        name = choice(fam_name) + " "+ choice(first_name)
        date_arr = datetime.date(2022, random.randint(1,12), random.randint(1,28))
        date_dep = datetime.date(2022, random.randint(date_arr.month,12), random.randint(date_arr.day,28))
        l.append(Reservation(numb, type, name, date_arr, date_dep))

    save_3(l)
    return l

gen()