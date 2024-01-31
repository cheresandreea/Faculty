import random


class Game:
    def __init__(self):
        self.sentences = []

    def add(self, sentence):
        for i in self.sentences:
            if i == sentence:
                raise ValueError("Duplicate sentences!")
        self.sentences.append(sentence)

    def get_all(self):
        return self.sentences

    def random(self):
        return random.choice(self.sentences)

    def finish(self, sentence):
        if "_" in sentence:
            return 0
        return 1

class File(Game):
    def __init__(self):
        super().__init__()
        self.load_()

    def load_(self):
        with open("sentences.txt", "r") as f:
            for i in f.readlines():
                self.sentences.append(i)

    def save(self):
        with open("sentences.txt", "w") as f:
            for i in self.sentences:
                f.write(i)
                f.write('\n')

    def add(self, sentence):
        super().add(sentence)
        self.save()
