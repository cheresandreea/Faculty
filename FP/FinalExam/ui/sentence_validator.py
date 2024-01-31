class Validator(object):
    def __init__(self, sentence):
        self.sentence = sentence

    def validate(self):
        if self.sentence == '':
            return False
        sentence = self.sentence.split()
        for i in sentence:
            print(i)
            if len(i) < 3:
                return False
            if i == ' ':
                return False
        return True