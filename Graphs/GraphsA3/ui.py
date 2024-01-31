import random

from Graph import Graph


def read(graph):
    """
    Reads a graph from a file.
    """
    file = open("file2.txt", "r")
    lines = file.readlines()
    n, m = map(int, lines[0].split())
    graph.n = n
    print(n)
    del lines[0]
    for i in range(m):
        x, y, cost = map(int, lines[i].split())

        if x not in graph.vertices:
            graph.vertices.append(x)
        if y not in graph.vertices:
            graph.vertices.append(y)

        graph.edges.append((x, y))
        graph.add_edge(x, y, cost)

    for vertex in graph.vertices:
        graph.adj_list[vertex] = []

        # Populate adjacency list based on the edges
    for (x, y) in graph.edges:
        graph.adj_list[x].append(y)

    file.close()


def write(graph):
    """
    Writes a graph to a file.
    """
    file = open("write.txt", "wt")
    file.write(str(graph.n) + " " + str(len(graph.edges)) + "\n")
    for edge in graph.edges:
        file.write(" ".join(map(str, edge)) + "\n")

    file.close()


def start():
    """
    Starts the user interface.
    """
    graph = Graph()
    read(graph)

    while True:
        print("1. Print the number of vertices")
        print("2. Print the set of vertices")
        print("3. Check if there is an edge from x to y")
        print("4. Add a vertex")
        print("5. Add an edge from x to y")
        print("6. Remove a vertex x")
        print("7. Write our graph in a file")
        print("8. Copy a graph in a text file")
        print("9. Print the adjacent list of a vertex x")
        print("10. Print the adjacent matrix of a graph")
        print("11. Print components of the graph")
        print("13. Print the lowest cost walk between two vertices")
        print("14. Print the list of vertices in topological sorting order")
        print("19. Exit")

        cmd = int(input("Give a command!"))
        if cmd == 1:
            print(graph.get_number_of_vertices())

        elif cmd == 2:
            print(graph.parse_vertices())

        elif cmd == 3:
            print("Give x and y!")
            x = int(input())
            y = int(input())
            if graph.existEdge(x, y):
                print("There is an edge from x to y!")
            else:
                print("There is no edge from x to y!")

        elif cmd == 4:
            print("Give x!")
            x = int(input())
            if x in graph.vertices:
                print("There is already a vertex x!")
            else:
                #graph.add_vertex(x)
                print("Vertex added!")

        elif cmd == 5:
            print("Give x and y!")
            x = int(input())
            y = int(input())
            if graph.existEdge(x, y):
                print("There is already an edge from x to y!")
            else:
                print("Give the cost!")
                cost = int(input())
                graph.add_edge(x, y, cost)
                print("Edge added!")

        elif cmd == 6:
            print("Give x: ")
            x = int(input())
            if graph.remove_vertex(x):
                print("Vertex removed!")
            else:
                print("Not in the list of vertices!")

        elif cmd == 7:
            write(graph)
            print("Graph written in file!")

        elif cmd == 8:
            graph2 = graph.copy_graph()
            print("Graph copied!")
            write(graph2)

        elif cmd == 9:
            print("Give x: ")
            x = int(input())
            if x not in graph.vertices:
                print("Not in the list of vertices!")
        #     else:
        #         print(graph.adj_list[x])
        #
        # elif cmd == 10:
        #     print(graph.adjacent())
        #
        # elif cmd == 11:
        #     print(graph.connected_components())
        #
        # elif cmd == 13:
        #     print("Give x and y!")
        #     x = int(input())
        #     y = int(input())
        #     print(graph.lowest_cost_walk(x, y))

        elif cmd == 14:
            print("Give x and y!")
            if(graph.TopoSort() == None):
                print("This graph has cycles!")
            else:
                print(graph.TopoSort())

        elif cmd == 19:
            break
