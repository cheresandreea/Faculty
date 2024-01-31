"""
Ui module for game

user commands:
    play 1, 1 #plays in the center ofthe board
    takeback  #undo the user's last move
    exit
"""
import board
import  game

def help_user():
    print(
    """
    user commands:
        play 1, 1  # plays in the center ofthe board
        takeback  # undo the user's last move
    """ )
def process_user_command(user_command):
    """
    :param user_command:
    :return:
    """

    user_command.strip()
    tokens = user_command.split(" ", maxsplit=1)
    command = tokens[0]
    tokens = tokens[1].split(",")

    for i in range(len(tokens)):
        tokens[i] = tokens[i].strip()

    return command, tokens

def start():
    game_board = board.create_board()
    while True:
        help_user()
        user_command = input(">")
        command, params = process_user_command(user_command)


        if command == 'play':
            row = int(params[0])
            col = int(params[1])
            game.human_move(game_board, row, col)

            game.computer.move(game_board)
            print("Computer moved at")

        elif command == 'takeback':
            pass
        elif command == 'exit':
            return
        else:
            print("Valid commands are")
            help_user()

#start()