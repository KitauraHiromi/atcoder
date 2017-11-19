# python2.7
import networkx as nx
from six import iteritems
from copy import deepcopy

DEBUG = False

def binary_search_in(li, val):
    '''
    required: li is sorted list.
    return val is in li or not.
    '''
    if DEBUG:
        print(li)
    if li == []:
        return False
    if val == li[0]:
        return True
    N = len(li)
    if val < li[N/2]:
        return binary_search(val, li[:N/2+1])
    else:
        return binary_search(val, li[N/2:])

def binary_search(li, val, lower=0, upper=None):
    '''
    required: li is sorted list.
    return index of val
    '''
    if lower < 0:
        return ValueError("lower must be non-negative")
    if upper is None:
        upper = len(li)
    while lower < upper:
        mid = (lower + upper) // 2
        if DEBUG:
            print(li[mid])
        if val == li[mid]:
            return mid
        if val < li[mid]:
            upper = mid
        else:
            lower = mid + 1
    return None

def bfs(graph, start, goal):
    '''
    required: graph is adjacent list and each edge cost is same.
    return shortest path from start to goal.
    '''
    visited, queue = [], [start]
    while queue:
        vertex = queue.pop(0)
        if vertex == goal:
            return visited

        if vertex not in visited:
            visited.append(vertex)
            queue.extend(graph[vertex] - set(visited))

    return None

def read_adjlist(adj_graph, view=False, prog="dot"):
    G = nx.DiGraph()
    for node, nbrs in iteritems(adj_graph):
        for nbr in nbrs:
            G.add_edge(node, nbr)
    if view:
        nx.nx_agraph.view_pygraphviz(G, prog=prog)
    return G


class Test_Case(object):
    def __init__(self):
        pass

    def binary_search_test(self):
        print(binary_search([1,2,3,4,5,6,7,8,9,10,11,12,13], 6))

    def bdf_test(self):
        test_graph = {'A': set(['B', 'C']),
                      'B': set(['A', 'D', 'E']),
                      'C': set(['A', 'F']),
                      'D': set(['B']),
                      'E': set(['B', 'F']),
                      'F': set(['C', 'E'])}
        read_adjlist(test_graph, view=True)

    def eight_puzzle(self):
        """
        example vertex: [1, 3, 5, 7, 0, 2, 4, 6, 8]
        0 means vacant space
        other each number means each card
        you can exchange 0 and neighbor card (neighbor is neighbor node in squares.)
        goal vertex: [0, 1, 2, 3, 4, 5, 6, 7, 8]
        print min exchange num
        """

        squares = {
            0: set([1, 3]),
            1: set([0, 2, 4]),
            2: set([1, 5]),
            3: set([0, 4, 6]),
            4: set([1, 3, 5, 7]),
            5: set([2, 4, 8]),
            6: set([3, 7]),
            7: set([4, 6, 8]),
            8: set([5, 7])
        }
        # visualize graph
        read_adjlist(squares, view=False, prog="neato")

        start = [8, 6, 7, 2, 5, 4, 3, 0, 1]
        # start = [1, 2, 3, 4, 5, 6, 7, 0, 8]
        goal = [1, 2, 3, 4, 5, 6, 7, 8, 0]

        def bfs(start, goal, max_iter=100000000):
            visited, queue, count = set(), [(start, [start])], 0
            while queue or count > max_iter:
                vertex, path = queue.pop(0)
                visited.add(tuple(vertex))
                count += 1

                # list is not hashable
                for nbr in squares[vertex.index(0)]:
                    tmp_vertex = deepcopy(vertex)
                    # exchange
                    tmp_vertex[vertex.index(0)] = tmp_vertex[nbr]
                    tmp_vertex[nbr] = 0
                    if tuple(tmp_vertex) not in visited:
                        if tmp_vertex == goal:
                            yield path + [tmp_vertex]
                        else:
                            queue.append((tmp_vertex, path + [tmp_vertex]))
        print(next(bfs(start, goal)))

if __name__ == "__main__":
    case = Test_Case()
    case.eight_puzzle()