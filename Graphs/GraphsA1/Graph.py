from copy import deepcopy

class Graph:
    def __init__(self):
        """
        Constructor for the Graph class.
        """
        self.n = 0
        self.din = {}
        self.dout = {}
        self.cost = {}


    def get_number_of_vertices(self):
        """
        Returns the number of vertices in the graph.
        """
        return self.n

    def parse_vertices(self):
        """
        Returns a list of vertices in the graph.
        """
        l = []
        for i in self.din:
            l.append(i)
        return l

    def existEdge(self, x, y):
        """
        Checks if an edge exists between two vertices.
        """
        if (x, y) in self.cost:
            return True
        return False

    def getInDegree(self, x):
        """
        Returns the in degree of a vertex.
        """
        if x not in self.din:
            return False
        return len(self.din[x])

    def getOutDegree(self, x):
        """
        Returns the out degree of a vertex.
        """
        if x not in self.dout:
            return False
        return len(self.dout[x])

    def parse_outbound_edges(self, x):
        """
        Returns a list of outbound edges of a vertex.
        """

        if x not in self.dout:
            return []
        return self.dout[x]

    def parse_inbound_edges(self, x):
        """
        Returns a list of inbound edges of a vertex.
        """

        if x not in self.din:
            return []
        return self.din[x]

    def add_edge(self, x, y, cost):
        """
        Adds an edge between two vertices.
        """

        # if x not in self.din and x not in self.dout:
        #     return False
        #
        # if y not in self.din and y not in self.dout:
        #     return False

        self.cost[(x, y)] = cost
        self.din[y].append(x)
        self.dout[x].append(y)


    def add_vertex(self, x):
        """
        Adds a vertex to the graph.
        """
        if x in self.din:
            return False

        self.din[x] = []
        self.dout[x] = []
        self.n += 1

    def get_cost_of_edge(self, x, y):
        """
        Returns the cost of an edge.
        """

        if (x, y) in self.cost:
            return self.cost[(x, y)]
        return False

    def modify_cost_of_edge(self, x, y, new_cost):
        """
        Modifies the cost of an edge.
        """
        if (x, y) in self.cost:
            self.cost[(x, y)] = new_cost
            return True
        return False

    def remove_edge(self, x, y):
        """
        Removes an edge between two vertices.
        """
        if (x, y) in self.din:
            self.din[y].remove(x)
            self.dout[x].remove(y)
            return True
        return False

    def remove_vertex(self, x):
        """
        Removes a vertex from the graph.
        """

        if x in self.din:
            for i in self.din[x]:
                self.dout[i].remove(x)
            if x in self.dout:
                for i in self.dout[x]:
                    self.din[i].remove(x)

            if x in self.din:
                del self.din[x]
            if x in self.dout:
                del self.dout[x]

            for i in range(len(self.cost)):
                if (x, i) in self.cost:
                    del self.cost[(x, i)]
                if(i, x) in self.cost:
                    del self.cost[(i, x)]
            self.n -= 1

            return True
        return False

    def get_endpoints(self, x, y):
        """
        Returns the endpoints of an edge.
        """
        if (x, y) in self.cost:
            return x, y
        return False

    def get_din(self):
        return self.din

    def get_dout(self):
        return self.dout

    def get_cost(self):
        return self.cost


    def copy_graph(self):
        """
        Returns a copy of the graph.
        """
        new_graph = Graph()
        new_graph.n = deepcopy(self.n)
        new_graph.din = deepcopy(self.din)
        new_graph.dout = deepcopy(self.dout)
        new_graph.cost = deepcopy(self.cost)
        return new_graph
