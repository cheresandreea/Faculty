import unittest

from A8.src.domain.person import Person
from A8.src.repository.person_repository import PersonRepository
from A8.src.services.person_service import PersonService


class TestRepo(unittest.TestCase):
    def setUp(self):
        self.person1 = Person(123, "Ana", "4099894")
        self.person2 = Person(3324, "Marial", "345245")
        self.repo = PersonRepository()
        self.service = PersonService()


    def test_add(self):
        self.repo.store(self.person1)
        self.assertIn(self.person1, self.repo.get_all())
        self.assertIn(self.person1, self.repo.get_all())


class testPerson(unittest.TestCase):

    def test1(self):
        obj = Person(12,"Ana", "073628233")
        self.assertEqual(obj.id, 12)
        self.assertEqual(obj.name, "Ana")
        self.assertEqual(obj.phone, "073628233")

    def test2(self):
        try:
            obj = Person(23, 324, "0743928")
        except Exception as e:
            assert str(e) == "Person should have the name string"

    def test3(self):
        obj = Person(23, 324, "0743928")
        obj.name = "ana"
        self.assertEqual(obj.name, "aa")