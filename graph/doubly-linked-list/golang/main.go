package main

import (
	"fmt"
)

type Node struct {
	value    int
	nextNode *Node
	prevNode *Node
}

func (node *Node) String() string {
	return fmt.Sprintf("Node(%d)", node.value)
}

func Create(value int) *Node {
	return &Node{value: value}
}

// method on a node struct
func (node *Node) setLeft(n *Node) {
	node.prevNode = n
}

// method on node struct
func (node *Node) setRight(n *Node) {
	node.nextNode = n
}

func fromList(alist []int) (*Node, *Node) {
	// this return first and the last node
	var firstNode *Node
	var currentNode *Node
	for _, val := range alist {
		// create a node out of it
		n := Create(val)
		if firstNode == nil {
			firstNode = n
		}
		if currentNode != nil {
			currentNode.setRight(n)
			n.setLeft(currentNode)
		}
		currentNode = n

	}

	return firstNode, currentNode
}

func traverseLeft(node *Node) *[]int {
	// what we can do is
	result := make([]int, 0)
	for {
		if node == nil {
			break
		}
		result = append(result, node.value)
		node = node.nextNode
	}
	return &result
}

func traverseRight(node *Node) *[]int {
	result := make([]int, 0)
	for {
		if node == nil {
			break
		}
		result = append(result, node.value)
		node = node.prevNode
	}
	return &result
}

func main() {
	// create a list
	alist := []int{1, 2, 3, 4, 5}
	firstNode, lastNode := fromList(alist)
	// print from left to right
	leftList := traverseLeft(firstNode)
	fmt.Println(leftList)

	// print from right to left
	rightList := traverseRight(lastNode)
	fmt.Println(rightList)
}
