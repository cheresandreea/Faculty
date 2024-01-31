class ControllerText():
    def __init__(self, repo):
        self.repo = repo
    def add_sentence(self, s):
        #add a sentence in a text file
        self.repo.add_sentence(s)

    def verify_sentence(self, s):
        self.repo.verify_sentence(s)

    def play_game(self):
        return self.repo.play_game()

    def start(self, sentence):
        #put the first and the last letter of the sentence in a list and '_' for the rest of the letters
        sentence = sentence.split()
        new_sentence = []
        for i in sentence:
            new_sentence.append(i[0])
            for j in range(1, len(i) - 1):
                new_sentence.append('_')
            new_sentence.append(i[-1])
            new_sentence.append(' ')
            



        return new_sentence