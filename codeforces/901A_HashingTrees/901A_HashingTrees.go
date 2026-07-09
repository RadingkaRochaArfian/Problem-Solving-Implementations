package main

import (
	"bufio"
	"os"
	"strconv"
)

func getFirstTree(a []int, total, h int) []int {
	vertexParent := make([]int, total)
	idxVertex := 1
	parent := make([]int, h+1)
	parent[0] = 1
	for i := 1; i <= h; i++ {
		prev_parent := parent[i-1]
		for range a[i] {
			vertexParent[idxVertex] = prev_parent
			idxVertex++
		}
		parent[i] = idxVertex - a[i] + 1
	}
	return vertexParent
}
func getSecondTree(a, tree []int) []int {
	var firsVertex int
	total := 0
	for i := range len(a) - 1 {
		total += a[i]
		if a[i] > 1 && a[i+1] > 1 {
			firsVertex = total
			break
		}
	}
	newTree := make([]int, len(tree))
	copy(newTree, tree)
	secondVertex := firsVertex + 1
	newTree[secondVertex]++
	return newTree
}
func solve(h int, scanner *bufio.Scanner) {
	a := make([]int, h+1)
	totalVertex := 0
	for i := range h + 1 {
		scanner.Scan()
		a[i], _ = strconv.Atoi(scanner.Text())
		totalVertex += a[i]
	}
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()
	ambiguous := false
	for i := range h {
		if a[i] > 1 && a[i+1] > 1 {
			ambiguous = true
		}
	}
	if !ambiguous {
		writer.WriteString("perfect\n")
		return
	}
	tree1 := getFirstTree(a, totalVertex, h)
	tree2 := getSecondTree(a, tree1)
	writer.WriteString("ambiguous\n")
	for i := range tree1 {
		writer.WriteString(strconv.Itoa(tree1[i]))
		if i < len(tree1) {
			writer.WriteByte(' ')
		}
	}
	writer.WriteByte('\n')
	for i := range tree2 {
		writer.WriteString(strconv.Itoa(tree2[i]))
		if i < len(tree2) {
			writer.WriteByte(' ')
		}
	}
	writer.WriteByte('\n')
}
func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	h, _ := strconv.Atoi(scanner.Text())
	solve(h, scanner)
}
