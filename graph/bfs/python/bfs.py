# -*- coding: utf-8 -*-
"""
  BFS.app
  ~~~~~~~~~
  :copyright: © 2018 by Robus Gauli
"""

import json

from collections import deque



# utils
def trace_path(node):
  if node:
    yield node.value
    yield from trace_path(node.parent)

  
class Node:

  def __init__(self, value):
    self.value = value
    self.edges = []
    self.visited = False
    self.parent = None
  
  def set_visited_flag(self, flag):
    if not isinstance(flag, bool):
      raise TypeError('Flag must be of type boolean.')
    self.visited = flag
  
  def connect(self, node):
    self.edges.append(node)
    node.edges.append(self)

  def set_parent(self, node):
    if not isinstance(node, Node):
      raise TypeError('Argument must be of type Node.')
    self.parent = node
    
  def __repr__(self):
    return 'Node({})'.format(self.value)

class Graph:

  def __init__(self, data):
    self.data = data
    #: map of value and node
    self.graph = {}
    self.nodes = []
  

  def extract_from_graph(self, title):
    return self.graph.setdefault(title, Node(title))
  
  def create_graph(self):
    movies = self.data.get('movies')
    for movie in movies:

      title = movie.get('title')
      movieNode = self.extract_from_graph(title)
      actors = movie.get('actors')
      
      for actor in actors:
        actorNode = self.extract_from_graph(actor)
        actorNode.connect(movieNode)
  



def traverse(graph, start, end):
  startNode = graph.graph.get(start)
  endNode = graph.graph.get(end)
  if not startNode or not endNode:
    raise ValueError('Node for a key is not found')
  queue = deque()
  queue.append(startNode)
  while queue:
    current_node = queue.popleft()
    if current_node.visited:
      continue
    current_node.set_visited_flag(True)
    if (current_node.value == endNode.value):
      return current_node
    
    for child in current_node.edges:
      print(child)
      if not child.visited:
        print('>> ', child)
        queue.append(child)
        child.set_parent(current_node)
     

         
    

def main():
  # load the json data into native python dictionary
  data = json.load(open('../data.json'))
  
  # create a graph out of the data
  graph = Graph(data)
  graph.create_graph()

  # traverse using bfs
  end_node = traverse(graph, 1, 5)
  
  # get the path of the end node
  path = list(trace_path(end_node))
  print(path)
  

if __name__ == '__main__':
  main()

