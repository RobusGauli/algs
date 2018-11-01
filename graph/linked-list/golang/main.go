package main

import "fmt"

type Node struct {
	value    int
	nextNode *Node
}

func fromList(alist []int) *Node {
	if len(alist) == 0 {
		panic("List cannot be empty.")
	}

	if len(alist) == 1 {
		return &Node{value: alist[0]}
	}
	return &Node{value: alist[0], nextNode: fromList(alist[1:])}
}

func traverseList(node *Node) *[]int {
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

func main() {
	list := []int{3, 4, 5, 6}

	node := fromList(list)
	traversedList := traverseList(node.nextNode)
	for _, num := range *traversedList {
		fmt.Println(num)
	}
}
