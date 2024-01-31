from random import choice


class Repository(object):
    def __init__(self):
        self._sentences = []

    def find_sentence(self, sentence):
        for i in self._sentences:
            if i == sentence:
                return True
            return False

    def verify_sentence(self, s):
        if self.find_sentence(s):
            raise ValueError("Sentence already exists")
        self.add_sentence(s)

    def add_sentence(self, s):
        self._sentences.append(s)

    def play_game(self):
        return choice(self._sentences)

class RepositoryText(Repository):
    def __init__(self):
        super().__init__()
        self._file_name = "in.txt"
        self._load_file()

    def add_sentence(self, s):
        #add a sentence in a text file
        super().add_sentence(s)
        self._save_file()

    def _load_file(self):
        try:
            f = open(self._file_name, "r")
            lines = f.readlines()
            for line in lines:
                self._sentences.append(line.strip())
            f.close()
        except IOError:
            pass


    def _save_file(self):
        f = open(self._file_name, "w")
        for s in self._sentences:
            f.write(s + '\n')


