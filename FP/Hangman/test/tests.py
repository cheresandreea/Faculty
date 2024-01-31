import datetime

from test.reservation import Reservation


def test():
    r = Reservation("01", "double", "Marius Adi", datetime.date(2022, 12, 23), datetime.date(2022, 12, 25))
    r.number = 1
    r.room_number = "01"
    r.name = "double"
    r.arrival = datetime.date(2022, 12, 24)
    r.departure = datetime.date(2022, 12, 26)
    assert (r.name == "double")
    assert (r.arrival == datetime.date(2022, 12, 24))

test()