import datetime

import texttable

from test.generation import gen


class UI:
    def __init__(self):
        self.reservations  = gen()

    def start(self):
        print("Give two dates: ")
        zi1 = int(input("ziua"))
        luna1 = int(input("luna"))
        an1 = int(input("an"))
        data1 = datetime.date(an1, luna1, zi1)
        zi2 = int(input("ziua"))
        luna2 = int(input("luna"))
        an2 = int(input("an"))
        data2 = datetime.date(an2, luna2, zi2)

        list1 = []
        for r in self.reservations:
            if r.arrival >= data1 and r.departure <= data2:
                list1.append(r)

        for i in list1:
            for j in list1:
                if i.arrival > j.arrival:
                    i, j = j, i
                else:
                    if i.arrival == j.arrival:
                        if i.name > j.name:
                            i, j = j, i


    def table(self):
        t = texttable.Texttable()
        mon = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"]
        for i in range(12):
            header = [mon[i], "Name", "Guests"]
            for r in self.reservations:
                if r.arrival.day == i+1:
                    t.add_row([str(r.arrival.month) + "." + str(r.arrival.day) + "-" + str(r.departure.month) + "." + str(r.departure.day), r.name, r.room_type])

            t.header(header)
            print(t.draw())

        #t.add_row(["February", "Name", "Guests"])


        #print(list1)

ui = UI()
#ui.start()
print(ui.table())