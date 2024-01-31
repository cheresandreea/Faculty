import copy
import random
import time


class Graph:
    def __init__(self, n):
        """
        Constructs a graph with n vertices numbered from 0 to n-1 and no edges
        :param n:
        """
        self.ins = {x:[] for x in range(n)}
        self.outs = {x:[] for x in range(n)}
        self.edges = []

    def add_Edge(self, x, y):
        """
        Adds an edge from x to y. Return True on success, False if the edge already exist.
        Precond: x and y exists
        """
        if (x, y) in self.edges:
            return False

        self.outs[x].append(y)
        self.ins[y].append(x)
        self.edges.append((x, y))
        return True

    def parseX(self):
        for x in self.outs.keys():
            yield x

    def parseNOut(self, x):
        return copy.copy(self.outs[x])

    def parseNIn(self, x):
        return copy.copy(self.ins[x])

    def isEdge(self, x, y):
        pass

def print_graph(g):
    print("Outbound")
    for x in g.parseX():
        print(x, ":", end = '')
        for y in g.parseNOut(x):
            print(y, ' ', end = '')
        print()
    print("Inbound")
    for x in g.parseX():
        print(x, ":", end='')
        for y in g.parseNIn(x):
            print(y, ' ', end='')
        print()

def parse_graph(g):
    before = time.time()
    for x in g.parseX():
        for y in g.parseNOut(x):
            pass
    after = time.time()
    print("Parse NOut: %sms" %(after-before)*1000)
    before =
    for x in g.parseX():
        for y in g.parseNIn(x):
            pass
    after = time.time()

def create_small_graph():
    g = Graph(3)
    for e in [(0, 0), (0, 1), (0, 2), (1, 2)]:
        g.add_Edge(e[0], e[1])
    return g

def create_ramdon_graph():
    g = Graph(n)
    while m > 0:
        x = random.randrange(n)
        y = random.randrange(n)
        if g.add_Edge(x, y):
            m = m -1
    return g

def main():
    g = create_small_graph()
    print_graph(g)

main()