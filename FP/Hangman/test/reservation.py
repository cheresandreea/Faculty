from datetime import date


class Reservation:
    def __init__(self, number: str, room_type: str, name: str, arrival: date, departure: date):
        self._number = number
        self._room_type = room_type
        self._name = name
        self._arrival = arrival
        self._departure = departure

    @property
    def number(self):
        return self._number

    @number.setter
    def number(self, value):
        self._number = value

    @property
    def room_type(self):
        return self._room_type

    @room_type.setter
    def room_type(self, value):
        self._room_type = value

    @property
    def name(self):
        return self._name

    @name.setter
    def name(self, value):
        self._name = value

    @property
    def arrival(self):
        return self._arrival

    @arrival.setter
    def arrival(self, value):
        self._arrival = value

    @property
    def departure(self):
        return self._departure

    @departure.setter
    def departure(self, value):
        self._departure = value

    def __repr__(self):
        return self.number + " " + self.room_type + " " + self.name + " " + str(self.arrival) + " " + str(self.departure) + "\n"