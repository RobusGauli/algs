
# class to represent a node
class Node:

  def __init__(self, value, next_node=None):
    self.value = value
    self.next_node = next_node


  def __repr__(self):
    return 'Node({})'.format(self.value)



# a function to create a linked list from the list
def from_list(alist=[]):
  if not alist:
    raise ValueError('List cannot be empty.')
  if len(alist) == 1:
    return Node(alist[0])
  return Node(alist[0], next_node=from_list(alist[1:]))

# a function to traverse a linked list
def traverse(node):
  if node:
    yield node.value
    yield from traverse(node.next_node)




if __name__ == '__main__':
  alist = list(range(10))
  node = from_list(alist)
  traversed_list = list(traverse(node))
  print(traversed_list)