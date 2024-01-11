
class Person:
    def __init__(self, id, name, phone):
        self.id = int(id)
        self.name = name
        self.phone = phone

    @property
    def id(self):
        return self._id

    @id.setter
    def id(self, value):
        self._id = value

    @property
    def name(self):
        return self._name

    @name.setter
    def name(self, value):
        self._name = value

    @property
    def phone(self):
        return self._phone

    @phone.setter
    def phone(self, value):
        self._phone = value


    def __str__(self):
        return "Id: " + str(self.id) + ", Name: " + self.name + ", Phone: " + self.phone

    def __repr__(self):
        return str(self)
