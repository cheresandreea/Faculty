class Activity:

    def __init__(self, ida, idp, date, time, description):
        self.ida = int(ida)
        self.idp = int(idp)
        self.date = date
        self.time = time
        self.description = description

    @property
    def ida(self):
        return self._ida

    @ida.setter
    def ida(self, value):
        self._ida = value

    @property
    def idp(self):
        return self._idp

    @idp.setter
    def idp(self, value):
        self._idp = value

    @property
    def date(self):
        return self._date

    @date.setter
    def date(self, value):
        self._date = value

    @property
    def time(self):
        return self._time

    @time.setter
    def time(self, value):
        self._time = value

    @property
    def description(self):
        return self._description

    @description.setter
    def description(self, value):
        self._description = value

    def __str__(self):
        return "Id activity: " + str(self.ida) + ", Id person: " + str(
            self.idp) + ", Date: " + self.date + ", Time: " + self.time + ", Description: " + self.description

    def __repr__(self):
        return str(self)
