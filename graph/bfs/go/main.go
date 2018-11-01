package main

import "fmt"

// a node that represents name and a age
type Node struct {
	value int
	node  *Node
}

func main() {
	// need to implement bfs on golang
	fmt.Println("Here we are to implement bfs on golang soon.")
	node := &Node{value: 3}
	fmt.Println(node)
}
