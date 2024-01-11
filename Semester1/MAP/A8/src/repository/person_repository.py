from datetime import date, time
from random import random, choice
import random
from A8.src.domain.person import Person
from A8.src.repository.repository_exception import RepositoryException

import os
class PersonRepository:

    def __init__(self):
        self._objects = []

    def store(self, obj: Person):
        if self.find(obj.id) is None:
            self._objects.append(obj)
        else:
            try:
                raise RepositoryException("Element having id=" + str(obj.id) + " already stored!")
            except RepositoryException as e:
                print(e)

    def find(self, objectId):
        for e in self._objects:
            if objectId == e.id:
                return e
        return None

    def find_name(self, n):
        l_name = []
        for p in self._objects:
            if p.name == n:
                l_name.append(p)

        return l_name

    def find_phone(self, n):
        l_phone = []
        for p in self._objects:
            if p.phone == n:
                l_phone.append(p)

        return l_phone

    def delete(self, objid):
        object = self.find(objid)
        if object is None:
            try:
                raise RepositoryException("Element not in repository!")
            except RepositoryException as e:
                print(e)
        else:
            self._objects.remove(object)
            return object

    def get_all(self):
        return self._objects

    def __repr__(self):
        return str(self)

    def __str__(self):
        r = ""
        for e in self._objects:
            r += str(e)
            r += "\n"
        return r

class TextFilePersonRepository(PersonRepository):
    def __init__(self, file_name="persons.txt"):
        super().__init__()
        self._file_name = file_name
        self.load_file()

    def load_file(self):
        with open(self._file_name, 'r') as f:
            data = f.read()
            lines = data.split('\n')
            try:
                for line in lines:
                    id, name, phone = line.split(', ')
                    new_person = Person(id, name, phone)
                    super().store(new_person)
            except ValueError:
                pass

    def save_file(self):
        with open(self._file_name, "wt") as f:
            for person in self.get_all():
                person_string = str(person.id) + ", " + person.name + ", " + person.phone + '\n'
                f.write(person_string)
        f.close()

    def store(self, new_person: Person):
        super().store(new_person)
        self.save_file()

    def delete(self, new_person):
        super().delete(new_person)
        self.save_file()

    def update(self, new_person: Person):
        if super().find(new_person.id) == None:
            try:
                raise RepositoryException("Element having id=" + str(new_person.id) + " does not exist!")
            except RepositoryException as e:
                print(e)
        else:
            old_person = super().find(new_person.id)
            old_person.name = new_person.name
            old_person.phone = new_person.phone
            self.save_file()


def test():
    p = Person(231, "Ana", "judo")
    r = PersonRepository()
    r.store(p)
    print(r.get_all())



if __name__ == "__main__":
    pass
