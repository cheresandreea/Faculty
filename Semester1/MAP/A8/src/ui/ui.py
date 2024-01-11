from datetime import datetime
import re
from A8.src.domain.activities import Activity
from A8.src.domain.person import Person
from A8.src.repository.activity_repository import TextFileActivityRepository
from A8.src.repository.person_repository import PersonRepository, TextFilePersonRepository
from A8.src.repository.repository_exception import RepositoryException, NotIntegerValue, NotValidString, NotOnlyDigits, \
    NotDateFormat, NotInIdPersons
from A8.src.services.activity_service import ActivityService
from A8.src.services.person_service import PersonService


class UI:
    def start(self):
        print("-Menu- \n\n"
              "Person operations: <add person>, <remove person>, <update person>, <list person> \n"
              "Activities operations: <add activity>, <remove activity>, <update activity>, <list activity>")

    def start_comands(self):
        repoPerson_object = TextFilePersonRepository()
        personService_object = PersonService(repoPerson_object)

        repoActivity_object = TextFileActivityRepository()
        activityService_object = ActivityService(repoActivity_object)

        while True:
            command = input("Give a command: ")
            if command == "add person":
                while True:
                    try:
                        try:
                            id = int(input("Give id: "))
                            if personService_object.find(id) is not None:
                                print("Duplicate id!")

                        except ValueError:
                            raise NotIntegerValue("This is not an integer number!")
                    except NotIntegerValue as e:
                        print(e.message)

                while True:
                    try:
                        try:
                            name = input("Give a name: ")
                            for c in name:
                                if not c.isalpha():
                                    raise NotValidString("Name should only contain characters!")
                            break
                        except TypeError:
                            raise NotValidString("Name should only contain characters!")
                    except NotValidString as e:
                        print(e)

                while True:
                    try:
                        try:
                            phone = input("Give phone number: ")
                            for c in phone:
                                if not c.isdigit():
                                    raise NotOnlyDigits("Phone must contain only digits!")
                            break
                        except TypeError:
                            raise NotOnlyDigits("Phone must contain only digits!")
                    except NotOnlyDigits as e:
                        print(e)

                person_object = Person(id, name, phone)




            elif command == "delete person":
                while True:
                    try:
                        try:
                            id = int(input("Give the id: "))
                            break
                        except ValueError:
                            raise NotIntegerValue("This is not an integer number!")
                    except NotIntegerValue as e:
                        print(e.message)
                personService_object.delete(id)
                print("Person succesfully deleted!")


            elif command == "update person":
                while True:
                    try:
                        try:
                            id = int(input("Give the id: "))
                            break
                        except ValueError:
                            raise NotIntegerValue("This is not an integer number!")
                    except NotIntegerValue as e:
                        print(e.message)
                while True:
                    try:
                        try:
                            new_name = input("Give the new name: ")
                            for c in new_name:
                                if not c.isalpha():
                                    raise NotValidString("Name should only contain characters!")
                            break
                        except TypeError:
                            raise NotValidString("Name should only contain characters!")
                    except NotValidString as e:
                        print(e)

                while True:
                    try:
                        try:
                            new_phone = input("Give the new phone number: ")
                            break
                        except ValueError:
                            raise NotIntegerValue("This is not an integer number!")
                    except NotIntegerValue as e:
                        print(e.message)
                new_object = Person(id, new_name, new_phone)
                personService_object.update(new_object)
                print("Person succesfully updated!")



            elif command == "list person":
                print(personService_object.get_all())


            elif command == "list activities":
                print(activityService_object.get_all())


            elif command == "add activity":
                while True:
                    try:
                        try:
                            ida = int(input("Give the id of the activity: "))
                            if activityService_object.find(ida) is not None:
                                print("Duplicate id!")

                        except ValueError:
                            raise NotIntegerValue("This is not an integer number!")
                    except NotIntegerValue as e:
                        print(e.message)
                while True:
                    try:
                        try:
                            idp = int(input("Give the id of the person: "))
                            l = []
                            with open("persons.txt", 'r') as f:
                                data = f.read()
                                lines = data.split('\n')
                                for line in lines:
                                    try:
                                        id, name, phone = line.split(', ')
                                        l.append(int(id))
                                    except ValueError:
                                        pass
                            if idp not in l:
                                try:
                                    raise NotInIdPersons("Id of the person does not exist!")
                                except NotInIdPersons as e:
                                    print(e)
                            else: break
                        except ValueError:
                            raise NotIntegerValue("This is not an integer number!")
                    except NotIntegerValue as e:
                        print(e.message)

                while True:
                    try:
                        try:
                            date = input("Give the date for the activity <format>: <YYYY-MM-DD>: ")
                            match = re.match(r'\d{4}-\d{2}-\d{2}', date)
                            if not match:
                                print("Date is NOT in the correct format")
                            else:
                                break
                        except ValueError:
                            raise NotDateFormat("This is not a correct format!")
                    except NotDateFormat as e:
                        print(e)

                while True:
                    try:
                        try:
                            time = input("Give the time when the activity will be: ")
                            timem = re.match(r'\d{2}:\d{2}:\d{2}',time)
                            if not timem:
                                print("Time is NOT in the correct format")
                            else:
                                break
                        except ValueError:
                            raise NotDateFormat("This is not a correct format!")
                    except NotDateFormat as e:
                        print(e)

                description = input("Give the activity you want to participate to: ")
                activity = Activity(ida, idp, str(date), str(time), description)

                if activityService_object.verif(activity) == 0:
                    print("Activity cannot be in the same time with other activity of a person!")
                else:
                    activityService_object.add(activity)
                    print("Activity succesfully added!")
            elif command == "delete activity":
                while True:
                    try:
                        try:
                            ida = input("Give the id of the activity: ")
                            break
                        except ValueError:
                            raise NotIntegerValue("This is not an integer number!")
                    except NotIntegerValue as e:
                        print(e.message)

                activityService_object.delete(ida)
            elif command == "update activity":
                while True:
                    try:
                        try:
                            l = []
                            idac = input("Give the activity id: ")
                            with open("activities.txt", 'r') as f:
                                data = f.read()
                                lines = data.split('\n')
                                for line in lines:
                                    try:
                                        ida, idp, date, time, description = line.split(', ')
                                        if ida == idac:
                                            idpers = idp
                                        l.append(ida)
                                    except ValueError:
                                        pass
                            if idac not in l:
                                try:
                                    raise NotInIdPersons("Id of the activity does not exist!")
                                except NotInIdPersons as e:
                                    print(e)
                            else:
                                break
                        except ValueError:
                            raise NotIntegerValue("This is not an integer number!")
                    except NotIntegerValue as e:
                        print(e.message)
                while True:
                    try:
                        try:
                            dates = input("Give the new date for the activity <format>: <YYYY-MM-DD>: ")
                            date = datetime.strptime(dates, "%Y-%m-%d")
                            break
                        except ValueError:
                            raise NotDateFormat("This is not a correct format!")
                    except NotDateFormat as e:
                        print(e)

                while True:
                    try:
                        try:
                            times = input("Give the new time when the activity will be: ")
                            time = datetime.strptime(times, '%H:%M:%S')
                            break
                        except ValueError:
                            raise NotDateFormat("This is not a correct format!")
                    except NotDateFormat as e:
                        print(e)

                description = input("Give the activity you want to participate to: ")

                #idp = activityService_object.get_id(ida)
                activity = Activity(ida, idpers, date, time, description)
                activityService_object.update(activity)
                print("Person succesfully updated!")
            elif command == "search person":
                print("1. By name \n"
                      "2. By phone number")
                c = input("> ")
                if c == "1":
                    n = input("Give a name: ")
                    if len(personService_object.find_name(n)) >= 1:
                        print(personService_object.find_name(n))
                    else:
                        print("Name does not exist!")
                elif c == "2":
                    n = input("Give the phone number: ")
                    if len(personService_object.find_phone(n)) >= 1:
                        print(personService_object.find_phone(n))
                    else:
                        print("Phone number does not exist!")

            elif command == "search activity":
                print("1. By date/time"
                      "2. By description")
                c = input("> ")
                if c == "1":
                    n = input("Give the date and the time <format>: <YYYY-MM-DD>")
                    m = input("Give the time <format>: <HH:MM:SS>: ")
                    if len(activityService_object.find_date(n, m)) > 1:
                        print(activityService_object.find_date(n, m))
                    else:
                        print("No activity with this date and time")
                elif c == "2":
                    n = input("Give the description: ")
                    if len(activityService_object.find_desc(n)) > 1:
                        print(activityService_object.find_desc(n))
                    else:
                        print("No activity with this description!")

            elif command == "statistics":
                print("1. Activities for a given date."
                      "2. Busiest days"
                      "3. Activities with a given person")
                n = input("> ")
                if n == "1":
                    pass

            else:
                print("Invalid command!")



if __name__ == "__main__":
    ui_object = UI()
    ui_object.start_comands()