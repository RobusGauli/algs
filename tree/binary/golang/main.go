package main

import (
	"fmt"
	"math/rand"
)

// Node to represent an entity in the tree
type Node struct {
	value   int
	left    *Node
	right   *Node
	visited bool
}

func (node *Node) String() string {
	return fmt.Sprintf("Node(%d)\n", node.value)
}

// Add an integer to a node
func (node *Node) Add(value int) {
	// this simply run the checks
	if value <= node.value {
		if node.left != nil {
			node.left.Add(value)
		} else {
			node.left = &Node{value: value}
		}
	} else {
		if node.right != nil {
			node.right.Add(value)
		} else {
			node.right = &Node{value: value}
		}
	}
}

func preOrderTraverse(node *Node, result *[]int) {

	if node != nil {
		preOrderTraverse(node.left, result)
		*result = append(*result, node.value)
		preOrderTraverse(node.right, result)
	}
}

func inOrderTraverse(node *Node, result *[]int) {
	if node != nil {
		*result = append(*result, node.value)
		inOrderTraverse(node.right, result)
		inOrderTraverse(node.left, result)
	}
}

func main() {
	// create a root node
	root := &Node{value: 30, visited: false}
	// create and array of 20 size items
	var items [20]int // zeroes valued

	for idx := range items {
		items[idx] = rand.Intn(100)
	}
	// add a value to the root node
	for _, item := range items {
		root.Add(item)
	}
	// traverse pre order traversal
	var r []int
	// traverse the root from left
	preOrderTraverse(root, &r)
	fmt.Println(r)

	// in order
	var n []int
	inOrderTraverse(root, &n)
	fmt.Println(n)
}
