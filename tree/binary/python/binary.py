# -*- coding: utf-8 -*-
"""
  binary.app
  ~~~~~~~~~
  :copyright: © 2018 by Robus Gauli
"""

import random

# utils


def pre_order(node):
    if node:
        yield from pre_order(node.left)
        yield node.value
        yield from pre_order(node.right)

# utils ends


class Node:
    """Node class holds value, left node and right node.
    :param value: integer value of the node.
    :param left: node to the left of the current node.
    :param right: node to the right of the current node.
    """

    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

    def add(self, value):
        if value <= self.value:
            if not self.left:
                self.left = Node(value)
            else:
                self.left.add(value)
        else:
            if not self.right:
                self.right = Node(value)
            else:
                self.right.add(value)

    def __repr__(self):
        return 'Node({}, left={}, right={})'.format(
            self.value,
            self.left.value if isinstance(
                self.left, self.__class__) else 'None',
            self.right.value if isinstance(
                self.right, self.__class__) else 'None'
        )


def main():
    # create a root
    root = Node(5)
    # populate tree
    alist = list(map(lambda _: random.randrange(40), range(10)))
    for item in alist:
        root.add(item)
    # pre order traversal
    sorted_list = list(pre_order(root))
    print(sorted_list)


if __name__ == '__main__':
    main()
