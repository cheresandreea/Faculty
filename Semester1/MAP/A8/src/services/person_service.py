from A8.src.domain.person import Person
from A8.src.repository.person_repository import PersonRepository


class PersonService:

    def __init__(self, repository):
        self.repository = repository

    def create(self, person_id, name, phone):
        person = Person(person_id, name, phone)
        self.repository.store(person)

    def add(self, person: Person):
        self.repository.store(person)

    def get_all(self):
        return self.repository.get_all()

    def delete(self, person_id):
        self.repository.delete(person_id)

    def update(self, new_person):
        self.repository.update(new_person)

    def find(self, id):
        return self.repository.find(id)

    def find_name(self, n):
        return self.repository.find_name(n)

    def find_phone(self, n):
        return self.repository.find_phone(n)




