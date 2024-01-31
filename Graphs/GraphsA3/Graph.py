class Graph:
    def __init__(self):
        """
        Constructor for the Graph class.
        """
        self.n = 0
        self.graph = {}
        self.vertices = []
        self.edges = []
        self.costs = {}
        self.adj_list = {}

    def get_number_of_vertices(self):
        """
        Returns the number of vertices in the graph.
        """
        return self.n

    def parse_vertices(self):
        """
        Returns a list of vertices in the graph.
        """
        return self.vertices

    def existEdge(self, x, y):
        """
        Checks if an edge exists between two vertices.
        """
        return (x, y) in self.edges

    def add_edge(self, x, y, cost):
        """
        Adds an edge between two vertices.
        """
        self.edges.append((x, y))
        self.costs[(x, y)] = cost

        if x not in self.graph:
            self.graph[x] = []
        self.graph[x].append(y)

    def add(self, x):
        """
        Adds a vertex to the graph.
        """
        if x not in self.vertices:
            self.vertices.append(x)

    def remove_edge(self, x, y):
        """
        Removes an edge between two vertices.
        """
        if (x, y) in self.edges:
            self.edges.remove((x, y))
            del self.costs[(x, y)]
            self.graph[x].remove(y)
            return True
        return False

    def remove_vertex(self, x):
        """
        Removes a vertex from the graph.
        """
        if x in self.vertices:
            self.vertices.remove(x)
            del self.graph[x]
            self.edges = [(a, b) for (a, b) in self.edges if a != x and b != x]
            self.costs = {(a, b): cost for (a, b), cost in self.costs.items() if a != x and b != x}
            return True
        return False

    def copy_graph(self):
        """
        Returns a copy of the graph.
        """
        new_graph = Graph()
        new_graph.n = self.n
        new_graph.vertices = self.vertices.copy()
        new_graph.edges = self.edges.copy()
        new_graph.costs = self.costs.copy()
        new_graph.graph = {k: v.copy() for k, v in self.graph.items()}
        return new_graph



    def TopoSortDFS(self, x, sorted, fullyProcessed, inProcess):
        inProcess.add(x)
        for y in self.adj_list[x]:
            if y in inProcess:
                return False
            elif y not in fullyProcessed:
                ok = self.TopoSortDFS(y, sorted, fullyProcessed, inProcess)
                if not ok:
                    return False
        inProcess.remove(x)
        sorted.append(x)
        fullyProcessed.add(x)
        return True

    def TopoSort(self):
        sorted = []
        fullyProcessed = set()
        inProcess = set()
        for x in self.vertices:
            if x not in fullyProcessed:
                ok = self.TopoSortDFS(x, sorted, fullyProcessed, inProcess)
                if not ok:
                    sorted = None
                    break
        return sorted