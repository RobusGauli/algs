# -*- coding: utf-8 -*-
"""
  Doubly Linked List
  ~~~~~~~~~~~~~~~~~~~~~~
  :copyright: 2018 Robus Gauli
"""

from collections.abc import Iterable

class Node:

  def __init__(self, value, prev_node=None, next_node=None):
    self.value = value
    self.prev_node = prev_node
    self.next_node = next_node
  
  def set_back_node(self, node):
    if not isinstance(node, Node):
      raise TypeError('argument must be of type Node.')
    self.prev_node = node
  
  def set_front_node(self, node):
    if not isinstance(node, Node):
      raise TypeError('Argument must be of type Node.')
    self.next_node = node


  def __repr__(self):
    return 'Node({})'.format(self.value)


def from_list(alist):
  if not isinstance(alist, Iterable):
    raise TypeError('Argument to the function must be iterable.')
  
  first_node = current_node = None

  for item in alist:
    # create a node out of it
    n = Node(item)
    if not first_node:
      first_node = n
    if current_node:
      n.set_back_node(current_node)
      current_node.set_front_node(n)
    current_node = n
  return first_node, current_node
    

# function to traverse from left to right
def traverse_left(node):
  if node:
    yield node.value
    yield from traverse_left(node.next_node)

# function to traverse from right to left
def traverse_right(node):
  if node:
    yield node.value
    yield from traverse_right(node.prev_node)
  
if __name__ == '__main__':
  first_node, last_node = from_list(range(10))
  # from left to right
  print(list(traverse_left(first_node)))
  # from right to left
  print(list(traverse_right(last_node)))
  
  