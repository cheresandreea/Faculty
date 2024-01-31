import random


class Service(object):
    def __init__(self, repo):
        self._repo = repo

    def update(self, row, col, symbol):
        self._repo.update(row, col, symbol)

    def get(self, row, col):
        return self._repo.get(row, col)

    def is_full(self):
        return self._repo.is_full()

    def place(self):
        if self.is_full():
            raise ValueError("No more moves")
        else:
            row = random.randint(0, 5)
            col = random.randint(0, 5)
            self._repo.update(row, col, "Y")

    def win(self):
        #win on a line
        for row in range(0, 5):
            ok = 1
            for i in range(0, 4):
                for j in range(i,5):
                    if self.get(row, i) != self.get(row, j):
                        ok = 0
            if ok == 1:
                return True, self.get(row, 0)

        # win on a col
        for col in range(0, 5):
            ok = 1
            for i in range(0, 4):
                for j in range(i, 5):
                    if self.get(i, col) != self.get(j, col):
                        ok = 0
            if ok == 1:
                return True, self.get(0, col)

        #win on diagonal

    def add(self, s):
        pass
