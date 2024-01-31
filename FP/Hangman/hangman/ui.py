import random

from hangman.game import Game, File
from hangman.service import Service


class UI:
    def __init__(self, repo, service):
        self.repo = repo
        self.service = service

    def start(self):
        while True:
            man = ["h", "a", "n", "g", "m", "a", "n"]
            x = 0
            s = input("Add a sentence: ")
            try:
                self.service.add(s)
            except ValueError as e:
                print(e)
            print(self.repo.get_all())

            op = input("Want to start the game? Y or N: ")
            if op == "Y":
                sentence = self.repo.random()
                final = self.service.reveal(sentence)
                print(final)
                while self.service.finish(final) == 0 and x < len(man):
                    letter = input("Give a letter: ")
                    if self.service.exists_letter(letter, sentence):
                        self.service.update(final, letter, sentence)
                        for i in final:
                            print(i, end = "")
                    else:
                        x = x + 1
                        for i in range(0, x):
                            print(man[i], end = "")
                if x == len(man):
                    print("YOU LOST")
                else:
                    print("YOU WON")






repo = File()
service = Service(repo)
ui = UI(repo, service)
ui.start()

