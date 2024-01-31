#implement order and chaos
import random

from texttable import Texttable


class Game:
    #make a 6x6 board
    def __init__(self):
        self.game_board = []

        for i in range(6):
            row = [0] * 6
            self.game_board.append(row)

#i want to do a fibo
    for i in range






    def __str__(self):
        t = Texttable()
        matrix = []
        for i in range(6):
            row = [0] * 6
            matrix.append(row)
        for i in range(6):
            for j in range(6):
                if self.game_board[i][j] == 0:
                    matrix[i][j] = 0
                else:
                    if self.game_board[i][j] == 1:
                        matrix[i][j] = 'X'
                    else:
                        matrix[i][j] = 'Y'
        t.add_rows(matrix)
        return t.draw()


    def add(self, x,y):
        self.game_board[x][y] = 1

    def make_move(self):
        x = random.randint(0, 5)
        y = random.randint(0, 5)
        self.game_board[x][y] = 2



def start():
    game = Game()
    print(game)
    while True:
        x = int(input("x = "))
        y = int(input("y = "))
        game.add(x, y)
        print(game)
        game.make_move()
        print(game.game_board)
        print(game)

start()