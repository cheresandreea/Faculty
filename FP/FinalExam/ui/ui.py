#we want to implement hangman game in python. The user can add sentences in a text file
from controller.ControllerText import ControllerText
from repository.RepositoryText import RepositoryText
from sentence_validator import Validator


class UI:
    def start(self):
        print("Welcome to Hangman game")

    def start_commands(self):
        repo = RepositoryText()
        controller = ControllerText(repo)
        while True:
            print("1. Add sentence")
            print("2. Play game")
            print("3. Exit")
            command = input(">")
            if command == "1":
                sentence = input("Add a sentence: ")
                sentence1 = Validator(sentence)
                if sentence1.validate():
                    try:
                        controller.verify_sentence(sentence)
                    except ValueError as ve:
                        print(ve)

            elif command == "2":
                print(controller.play_game())
                print(controller.start(controller.play_game()))
                pass
            elif command == "3":
                break
            else:
                print("Invalid command")

ui = UI()
ui.start()
ui.start_commands()


