from datetime import date, time
from random import random, choice
import random
from A8.src.domain.activities import Activity
from A8.src.domain.person import Person
from A8.src.repository.activity_repository import ActivityRepository, TextFileActivityRepository
from A8.src.repository.person_repository import PersonRepository, TextFilePersonRepository
import os

def generate_persons(n):
    name = ["Pop", "Pastiu", "Horvath", "Muntean", "Moldovan", "Satmarean", "Vadau", "Bindea"]
    surname = ["Ana", "Maria", "Patricia", "Gabriela", "Antonia", "Gabriel", "Andrei", "Paul", "Vlad", "Marius"]
    person_list = []
    for i in range(n):
        idp = random.randint(1000, 9999)
        person_name = choice(list(name)) + " " + choice(list(surname))
        phone_number = "07" + str(random.randint(10000000, 99999999))
        person = Person(idp, person_name, phone_number)
        person_list.append(person)

    return person_list



def generate_activities(n):
    description = ["dance", "yoga", "football", "tennis", "judo", "basketball", "ski", "ping-pong", "ballet"]
    l = []
    list_of_activities = []
    path = "persons.txt"
    with open(path, 'r') as f:
        data = f.read()
        lines = data.split('\n')
        for line in lines:
            try:
                id, name, phone = line.split(', ')
                l.append(id)
            except ValueError:
                pass

    for i in range(n):
        id_activity = random.randint(100, 999)
        id_person = random.choice(l)
        data = str(date(random.randint(2022, 2023), random.randint(1, 12), random.randint(1, 28)))
        timp = str(time(random.randint(8, 20), random.randint(1, 12)))
        activity = Activity(id_activity, id_person, str(data), str(timp), random.choice(description))
        list_of_activities.append(activity)

    return list_of_activities


def start():
    if os.path.exists("persons.txt"):
        os.remove("persons.txt")
        open("persons.txt", 'a').close()

    else:
        print("The file does not exist")
        open("persons.txt", 'a').close()

    if os.path.exists("activities.txt"):
        os.remove("activities.txt")
        open("activities.txt", 'a').close()

    else:
        print("The file does not exist")
        open("activities.txt", 'a').close()
    n = 20
    p = generate_persons(n)
    repo_text_file = TextFilePersonRepository("persons.txt")

    for c in p:
        repo_text_file.store(c)

    a = generate_activities(n)
    repoA = TextFileActivityRepository("activities.txt")


    for c in a:
        repoA.store(c)

start()