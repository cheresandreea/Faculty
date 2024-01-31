import random

from Graph import Graph

def read(graph):
    """
    Reads a graph from a file.
    """
    file = open("graph.txt", "r")
    lines = file.readlines()
    n = int(lines[0].split()[0])
    graph.n = n
    m = int(lines[0].split()[1])
    del lines[0]
    for i in lines:
        x = int(i.split()[0])
        y = int(i.split()[1])

        cost = int(i.split()[2])

        graph.cost[(x, y)] = cost

        if x in graph.dout:
            graph.dout[x].append(y)
        else:
            graph.dout[x] = []
            graph.dout[x].append(y)

        if x not in graph.din:
        #     graph.din[x].append(y)
        # else:
           graph.din[x] = []
        #     graph.din[x].append(y)

        if y in graph.din:
            graph.din[y].append(x)
        else:
            graph.din[y] = []
            graph.din[y].append(x)

        if y not in graph.dout:
        #     graph.dout[y].append(x)
        # else:
            graph.dout[y] = []
        #     graph.dout[y].append(x)

    file.close()


def write(graph):
    """
    Writes a graph to a file.
    """
    file = open("write.txt", "wt")
    file.write(str(graph.n) + " " + str(len(graph.cost)) + "\n")
    for i in graph.cost:
        file.write(str(i[0]) + " " + str(i[1]) + " " + str(graph.cost[(i[0], i[1])]) + "\n")
    file.close()


def createRandomGraph(n, m):
    """
    Creates a random graph with n vertices and m edges.
    """

    graph = Graph()
    print(n)
    for i in range(m):
        x = random.randint(0, n-1)
        y = random.randint(0, n-1)
        cost = random.randint(0, 100)
        graph.add_edge(x, y, cost)

    print(graph.dout)
    print(graph.din)
    return graph


def start():
    """
    Starts the user interface.
    """
    graph = Graph()
    read(graph)

    # print(graph.din)
    # print(graph.cost)
    # print(graph.dout)
    while True:
        print("1. Print the number of vertices")
        print("2. Print the set of vertices")
        print("3. Check if there is an edge from x to y")
        print("4. Print the number of in-degree of a vertex x")
        print("5. Print the number of out-degree of a vertex x")
        print("6. Parse the set of outbound edges of a vertex x")
        print("7. Parse the set of inbound edges of a vertex x")
        print("8. Add an edge from x to y")
        print("9. Add a vertex")
        print("10. Get the cost of an edge")
        print("11. Modify the cost of an edge")
        print("12. Remove a vertex x")
        print("13. Write our graph in a file")
        print("14. Create a random graph")
        print("15. Copy a graph in a text file")
        print("16. Get the end points of an edge")
        print("17. See all dictionaries")
        print("18. Exit")


        cmd = int(input("Give a command!"))
        if cmd == 1:
            print(graph.get_number_of_vertices())

        elif cmd == 2:
            print(graph.parse_vertices())

        elif cmd == 3:
            print("Give x and y!")
            x = int(input())
            y = int(input())
            if(graph.existEdge(x, y) == True):
                print("There is an edge from x to y!")
            else:
                print("There is no edge from x to y!")

        elif cmd == 4:
            print("Give x!")
            x = int(input())
            if(graph.getInDegree(x) == False):
                print("There is no vertex x!")
            else:
                print(graph.getInDegree(x))

        elif cmd == 5:
            print("Give x!")
            x = int(input())
            if(graph.getOutDegree(x) == False):
                print("There is no vertex x!")
            else:
                print(graph.getOutDegree(x))

        elif cmd == 6:
            print("Give x!")
            x = int(input())
            if(graph.parse_outbound_edges(x) == False):
                print("There is no vertex x!")
            else:
                print(graph.parse_outbound_edges(x))

        elif cmd == 7:
            print("Give x!")
            x = int(input())
            if(graph.parse_inbound_edges(x) == False):
                print("There is no vertex x!")
            else:
                print(graph.parse_inbound_edges(x))

        elif cmd == 8:
            print("Give x, y and cost!")
            x = int(input())
            y = int(input())
            cost = int(input())
            if (x, y) in graph.cost:
                print("There is already an edge from x to y!")
            else:
                if graph.add_edge(x, y, cost) == False:
                    print("There is no vertex x or y!")
                else:
                    print("Edge added!")

        elif cmd == 9:
            print("Give x!")
            x = int(input())
            if x in graph.din:
                print("There is already a vertex x!")
            else:
                graph.add_vertex(x)
                print("Vertex added!")

        elif cmd == 10:
            print("Give x and y!")
            x = int(input())
            y = int(input())
            if graph.get_cost_of_edge(x, y) == False:
                print("There is no edge from x to y!")
            else:
                print(graph.get_cost_of_edge(x, y))

        elif cmd == 11:
            print("Give x, y and cost!")
            x = int(input())
            y = int(input())
            cost = int(input())
            if graph.modify_cost_of_edge(x, y, cost) == False:
                print("There is no edge from x to y!")
            else:
                print("Cost modified!")


        elif cmd == 12:
            print("Give x: ")
            x = int(input())
            if(graph.remove_vertex(x) == True):
                print("Vertex removed!")
            else:
                print("Not in the list of vertices!")

        elif cmd == 13:
            write(graph)
            print("Graph written in file!")

        elif cmd == 14:
            print("Give n and m!")
            n = int(input())
            m = int(input())
            graph1 = createRandomGraph(n, m)
            print(graph1.get_din())
            print(graph1.get_dout())
            print(graph1.get_cost())

        elif cmd == 15:
            graph2 = graph.copy_graph()
            print("Graph copied!")
            write(graph2)

        elif cmd == 16:
            print("Give x and y!")
            x = int(input())
            y = int(input())
            if graph.get_endpoints(x, y) == True:
                print(graph.get_endpoints(x, y))
            else:
                print("There is no edge from x to y!")

        elif cmd == 17:
            print(graph.get_din())
            print(graph.get_dout())
            print(graph.get_cost())
        elif cmd == 18:
            break
        else:
            print("Invalid command!")

