import random

from texttable import Texttable


class Minefield:
    def __init__(self, rows, col, mines: int):
        self._rows = rows
        self._col = col
        self._mines = mines
        """
        Data rep:
        None -> empty square
        """
        self._data = ['0'] * ((self._rows + 2) * (self._col + 2))
        self._mines_laid = False

    def reveal(self, row, col: int):
        if not self._mines_laid:
            self._lay_mines(row, col)
            self._mines_laid = True

    def _lay_mines(self, empty_row, empty_col):
        locations = []
        for i in range(1, self._rows + 1):
            for j in range(1, self._col + 1):
                #if i != empty_row or j != empty_col:
                    locations.append((i, j))
        random.shuffle(locations)
        for i in range(self._mines):
            x, y = locations.pop(0)
            self._data[x * self._col + y] = 'x'

    def __str__(self):
        t = Texttable()
        t.set_max_width(0)

        # FIXME separate into another function so we don t recompute header at each__Str__call
        header = ['/']
        for i in range(0, self._col):
            header.append(chr(ord('A') + i))

        t.header(header)
        for i in range(self._col + 1, self._rows * (self._col + 2), self._col + 2):
            t.add_row([i // (self._col + 1)] + self._data[i: i + self._col])

        return t.draw()

        # function that returns if a number is prime
    def is_prime(n):
        if n == 1:
            return False
        if n == 2:
            return True
        for i in range(2, n):
            if n % i == 0:
                return False
        return True






field = Minefield(8, 5, 12)
field.reveal(0, 0)
print(field.__str__())
