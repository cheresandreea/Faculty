#make order of chaos game with x and 0
import random

import texttable


class RepoBoard:
    def __init__(self):
        self.board = []
        for i in range (6):
            row = [0] * 6
            self.board.append(row)


    def update(self, row, col, symbol):
        if self.board[row][col] == 0 and row>=0 and row<=5 and col>=0 and col<=5:
            self.board[row][col] = symbol
        else:
            raise ValueError("You can t move here")

    def get(self, row, col):
        return self.board[row][col]

    def is_full(self):
        for row in self.board:
            for col in row:
                if col == 0:
                    return False
        return True



    def __str__(self):
        t = texttable.Texttable()
        t.set_max_width(0)

        # header = ['/']

        # list = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"]
        # for i in range(0, 5):
        #     header.append(list[i])

        #t.header(header)
        for row in range(0, 5):
            t.add_row(self.board[row])

        return t.draw()
