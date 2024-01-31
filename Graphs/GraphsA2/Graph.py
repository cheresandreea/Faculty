from copy import deepcopy

#5. Write a program that, given a graph with costs and two vertices,
# finds a lowest cost walk between the given vertices, or prints a
# message if there are negative cost cycles accessible from the starting
# vertex. The program will use the Ford's algorithm.


class Graph:
    def __init__(self):
        """
        Constructor for the Graph class.
        """
        self.n = 0
        self.vertices = []
        self.edges = []
        self.adj_list = {}
        self.costs = {}

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
        for i in self.vertices:
            l.append(i)

        return l

    def existEdge(self, x, y):
        """
        Checks if an edge exists between two vertices.
        """
        if (x, y) in self.edges:
            return True
        return False

    def add_edge(self, x, y):
        """
        Adds an edge between two vertices.
        """

        if x not in self.adj_list:
            self.adj_list[x] = []
        self.adj_list[x].append(y)

        if y not in self.adj_list:
            self.adj_list[y] = []
        self.adj_list[y].append(x)

    def add_vertex(self, x):
        """
        Adds a vertex to the graph.
        """
        if x in self.vertices:
            return False
        self.vertices.append(x)

    def remove_edge(self, x, y):
        """
        Removes an edge between two vertices.
        """
        if (x, y) in self.edges:
            self.edges.remove((x, y))
            return True
        return False

    def remove_vertex(self, x):
        """
        Removes a vertex from the graph.
        """
        if x in self.vertices:
            self.vertices.remove(x)
            return True
        return False

    def copy_graph(self):
        """
        Returns a copy of the graph.
        """
        new_graph = Graph()
        new_graph.n = deepcopy(self.n)
        new_graph.vertices = deepcopy(self.vertices)
        return new_graph

    def adjacent(self):
        """
        Returns a list of adjacent vertices of a vertex.
        """
        return self.adj_list

    def adjacentx(self, x):
        """
        Returns a list of adjacent vertices of a vertex.
        """
        return self.adj_list[x]

    # Write a program that finds the connected components of an undirected graph using a depth-first traversal of the graph
    def dfs(self, v, visited, component):
        """
        A recursive function to perform depth-first traversal.
        """
        visited[v] = True
        component.append(v)
        for neighbour in self.adj_list[v]:
            if not visited[neighbour]:
                self.dfs(neighbour, visited, component)

    def connected_components(self):
        """
        Returns a list of connected components of the graph.
        """
        visited = {v: False for v in self.vertices} # initialize all vertices as unvisited
        components = []
        for vertex in self.adj_list:
            #print(vertex)
            if not visited[vertex]:
                component = []
                self.dfs(vertex, visited, component)
                components.append(component)
        return components

    def create_graphs(self):
        c = self.connected_components()
        for i in range(0, len(c)):
            print("The component " + str(i + 1) + ": ")
            print(c[i], ":")

            g = Graph()
            for j in c[i]:
                for k in c[i]:
                    if self.existEdge(j, k):
                        g.add_edge(j, k)
            print(g.adj_list)
            print('\n')



def BellmanFord(graph, s, t):
    if s not in graph.vertices or t not in graph.vertices:
        return None

    distance = {v: float('inf') for v in graph.vertices}
    predecessor = {}

    distance[s] = 0
    changed = True
    while changed:
        changed = False
        for(x,y) in graph.edges:
            if distance[y] > distance[x] + graph.costs[(x,y)]:
                distance[y] = distance[x] + graph.costs[(x,y)]
                predecessor[y] = x
                changed = True

    if distance[t] == float('inf'):
        return None
    else:
        prev = []
        a = t
        while a != s:
            prev.append(a)
            a = predecessor[a]
            if a == s:
                prev.append(s)

        walk = {}

        return prev, distance[t]
