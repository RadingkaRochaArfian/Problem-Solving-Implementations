package main

import (
	"bufio"
	"fmt"
	"os"
	"slices"
)

var writer *bufio.Writer = bufio.NewWriter(os.Stdout)
var reader *bufio.Reader = bufio.NewReader(os.Stdin)

func printf(f string, a ...any) { fmt.Fprintf(writer, f, a...) }
func scan(a ...any)             { fmt.Fscan(reader, a...) }
func findDescDfs(n int, arr []int, graph [][]int) []int {
	vis := make([]bool, n+1)
	ans := make([]int, n+1)
	for i := range n {
		node := i + 1
		if vis[node] {
			continue
		}
		stack := []int{node}
		vis[node] = true
		pos := []int{}
		val := []int{}
		for len(stack) > 0 {
			top := len(stack) - 1
			v := stack[top]
			stack = stack[:top]

			pos = append(pos, v)
			val = append(val, arr[v])
			for _, adj := range graph[v] {
				if !vis[adj] {
					vis[adj] = true
					stack = append(stack, adj)
				}
			}
		}
		slices.Sort(pos)
		slices.Sort(val)
		slices.Reverse(val)
		for j := range len(pos) {
			ans[pos[j]] = val[j]
		}
	}
	return ans
}
func solve(n, m int) {
	arr := make([]int, n+1)
	for i := range n {
		scan(&arr[i+1])
	}
	graph := make([][]int, n+1)
	for range m {
		var a, b int
		scan(&a, &b)
		graph[a] = append(graph[a], b)
		graph[b] = append(graph[b], a)
	}
	ans := findDescDfs(n, arr, graph)
	for i := range ans {
		if i == 0 {
			continue
		}
		printf("%d ", ans[i])
	}
	printf("\n")
}
func main() {
	defer writer.Flush()
	var n, m int
	scan(&n, &m)
	solve(n, m)
}
