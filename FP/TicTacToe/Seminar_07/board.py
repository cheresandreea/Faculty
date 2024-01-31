"""
Board module
"""

def create_board():
    """
    Create the game board
    :return: the board
    """

    board = []
    for i in [0, 1, 2]:
        board.append([' ', ' ', ' '])
    return board

def get_symbol(game_board, row, col):
   symbol = game_board[row][col]
   return symbol if not ' ' else None

def move_on_board(game_board, symbol, row, col):
    """
    :param game_board: The game board
    :param symbol: one of 'X' or '0'
    :param row: one of 0, 1, 2
    :param col: one of 0, 1, 2
    :return: None
    Raise valueError if (row, col) outside board, symbol not one of (X, 0)
    and if square is already taken
    """

    if row not in [0, 1, 2] or col not in [0, 1, 2]:
        raise ValueError("Move outside the board")
    if symbol not in ['X', '0']:
        raise ValueError("Invalid Symbol")
    if get_symbol(game_board, row, col) is not None:
        raise ValueError("Square already taken")



    game_board[row][col] = symbol

def test_move_on_board():
    b = create_board()
    for row in [0, 1, 2]:
        for col in [0, 1, 2]:
            assert get_symbol(b, row, col) is None

    move_on_board(b, 'X', 1, 1)
    assert get_symbol(b, 1, 1) == 'X'
    move_on_board(b, 'X', 0, 0)
    assert get_symbol(b, 0, 0) == 'X'
    move_on_board(b, '0', 2, 2)
    assert get_symbol(b, 2, 2) == '0'

    #check error
    try:
        move_on_board(b, 'X', 1, 1)
        assert False
    except ValueError:
        assert True

def str_board(game_board):
    result = ""
    gb = game_board

    for row in [0, 1, 2]:
        result += gb[0][0] + "|" + gb[0][1] + "|" + gb[0][2] + '\n'
        result += "-+-+-+" + '\n'


    return result


b = create_board()
print(str_board(b))
