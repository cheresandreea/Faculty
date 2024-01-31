class Service(object):
    def __init__(self, repo):
        self.repo = repo

    def add(self, sentence):
        """
        :param sentence:
        :return:
        """

        if len(sentence) < 1 or sentence == " ":
            raise ValueError("Sentence does not have at least 1 word!")

        for i in sentence.split():
            if len(i) <= 2:
                raise ValueError("Sentence does not have all words of at least 3 characters!")

        self.repo.add(sentence)

    def reveal(self, sentence):
        s = []
        final =[]
        letters = ['_']
        for i in range(0, len(sentence)):
            if i == 0 or i == len(sentence)-1:
                s.append(sentence[i])
                if sentence[i] not in letters:
                    letters.append(sentence[i])
            elif i < len(sentence) - 1 and (sentence[i - 1] == " " or sentence[i + 1] == " "):
                s.append(sentence[i])
                if sentence[i] not in letters:
                    letters.append(sentence[i])
            elif sentence[i] == " ":
                s.append(" ")
                if sentence[i] not in letters:
                    letters.append(sentence[i])
            else:
                s.append("_")


        for i in sentence:
            if i in letters:
                final.append(i)
            else:
                final.append("_")

        return final

    def exists_letter(self, l, sen):
        if l in sen:
            return 1
        return 0

    def update(self, final, l, sentence):
        for i in range(0, len(sentence)):
            if sentence[i] == l:
                final[i] = l
        return final

    def finish(self, final):
        if "_" in final:
            return 0
        return 1

