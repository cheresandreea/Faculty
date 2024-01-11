class ActivityService:
    def __init__(self, repository):
        self.repository = repository

    def add(self, activity):
        self.repository.store(activity)

    def get_all(self):
        return self.repository.get_all()

    def delete(self, ida):
        self.repository.delete(ida)

    def get_id(self, ida):
        return self.repository.get_id(ida)

    def update(self, activity):
        self.repository.update(activity)

    def verif(self, obj):
        return self.repository.verif(obj)

    def find(self, obj):
        return self.repository.find(obj)

    def find_date(self, n, m):
        return self.repository.find_date(n, m)

    def find_desc(self, n):
        return self.repository.find_desc(n)