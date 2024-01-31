class Flight:
    def __init__(self, id, dep_city, dep_city_time, arr_city, arr_city_time):
        self._id = id
        self._dep_city = dep_city
        self._dep_city_time = dep_city_time
        self._arr_city = arr_city
        self._arr_city_time = arr_city_time


    @property
    def id(self):
        return self._id

    @id.setter
    def id(self, value):
        self._id = value

    @property
    def dep_city(self):
        return self._dep_city

    @dep_city.setter
    def dep_city(self, value):
        self.dep_city = value

    @property
    def dep_city_time(self):
        return self._dep_city_time

    @dep_city_time.setter
    def dep_city_time(self, value):
        self._dep.city,time = value

    @property
    def arr_city(self):
        return self._arr_city

    @arr_city.setter
    def arr_city(self, value):
        self._arr_city = value

    @arr_city.setter
    def arr_city_time(self):
        return self._arr_city_time

    @arr_city_time.setter
    def arr_city_time(self, value):
        self._arr_city_time = value


if __name__ == '__main__':
    f = Flight(12, "Cluj", "12:30", "Vienna", "14:20")
    print(f.dep_city_time)