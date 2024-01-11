from datetime import date, time
from random import random, choice
import random
from A8.src.domain.activities import Activity
from A8.src.domain.person import Person
from A8.src.repository.person_repository import PersonRepository
from A8.src.repository.repository_exception import RepositoryException


class ActivityRepository:

    def __init__(self):
        self._objects = []

    def store(self, obj: Activity):
        if self.find(obj.ida) is None:
            self._objects.append(obj)
        else:
            try:
                raise RepositoryException("Element having id=" + str(obj.ida) + " already stored!")
            except RepositoryException as e:
                print(e)


    def find(self, objectId):
        for e in self._objects:
            if objectId == e.ida:
                return e
        return None

    def find_date(self, date, time):
        l = []
        for e in self._objects:
            if date == e.date and time == e.time:
                l.append(e)
        return None

    def find_desc(self, n):
        l = []
        for e in self._objects:
            if n == e.description:
                l.append(e)
        return None


    def delete(self, objid):
        object = self.find(objid)
        if object is None:
            raise RepositoryException("Element not in repository!")
        self._objects.remove(object)
        return object

    def get_all(self):
        return self._objects

    def __repr__(self):
        return str(self)

    def verif(self, obj: Activity):
        for a in self._objects:
            if obj.idp == a.idp:
                if obj.date == a.date:
                    if obj.time == a.time:
                        return 0
        return 1



def test():
    a = Activity(231, 235, "2022-02-03", "12:09:00", "judo")
    r = ActivityRepository()
    r.store(a)
    print(r.get_all())

class TextFileActivityRepository(ActivityRepository):
    def __init__(self, filename="activities.txt"):
        super().__init__()
        self._filename = filename
        self.load_file()

    def load_file(self):
        with open(self._filename, "r") as f:
            data = f.read()
            lines = data.split('\n')
            try:
                for line in lines:
                    ida, idp, data, time, description = line.split(", ")
                    new_activity = Activity(ida, idp, data, time, description)
                    super().store(new_activity)
            except ValueError:
                pass

    def save_file(self):
        with open(self._filename, "wt") as f:
            for activity in self.get_all():
                activity_string = str(activity.ida) + ", " + str(activity.idp) + ", " + str(activity.date) + ", " + str(activity.time) + ", " + activity.description + '\n'
                f.write(activity_string)
        f.close()

    def store(self, activity):
        super().store(activity)
        self.save_file()

    def delete(self, ida):
        super().delete(ida)
        self.save_file()


    def update(self, activity):
        if super().find(activity.ida) == None:
            try:
                raise RepositoryException("Activity having id=" + str(activity.ida) + " does not exist!")
            except RepositoryException as e:
                print(e)
        else:
            print()
            old_activity = super().find(activity.ida)
            old_activity.date = activity.date
            old_activity.time = activity.time
            old_activity.description = activity.description
            self.save_file()


if __name__ == "__main__":
    pass
