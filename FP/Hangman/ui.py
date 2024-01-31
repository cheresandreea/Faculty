from repo import RepoBoard
from service import Service


class UI(object):

    def start(self):
        board = RepoBoard()
        service_board = Service(board)
        print(board)
        while not board.is_full() and service_board.win():
            ok = 1
            print("Place a symbol:")
            try:
                row = int(input("Row: "))
                col = int(input("Column: "))
                symbol = input("Symbol: ")
                try:
                    service_board.update(row, col, symbol)
                except ValueError as e:
                    print (e)
                    ok = 0


            except:
                print("Invalid!")
                ok = 0
            if ok == 1:
                service_board.place()



            print(board)





if __name__ == "__main__":
    ui = UI()
    ui.start()