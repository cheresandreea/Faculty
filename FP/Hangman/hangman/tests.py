from unittest import TestCase

from hangman.game import Game
from hangman.service import Service


def test():
    repo = Game()
    se = Service(repo)
    s = "Ana are mere"
    se.add(s)
    assert se.repo.sentences == ['Ana are mere']
    assert se.reveal(s) == ['A', '_', 'a', ' ', 'a', '_', 'e', ' ', 'm', 'e', '_', 'e']


test()