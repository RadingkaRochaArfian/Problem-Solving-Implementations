package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

var writer *bufio.Writer = bufio.NewWriter(os.Stdout)
var reader *bufio.Reader = bufio.NewReader(os.Stdin)

func printf(f string, a ...any) { fmt.Fprintf(writer, f, a...) }
func scan(a ...any)             { fmt.Fscan(reader, a...) }
func solve(n, m int) {
	arrColor := make([]int, n)
	for i := range n {
		scan(&arrColor[i])
	}
	graph := make([][]int, n)
	for range m {
		var l, r int
		scan(&l, &r)
		l--
		r--
		graph[l] = append(graph[l], r)
		graph[r] = append(graph[r], l)
	}
	arrVis := make([]bool, n)
	totalChange := 0
	for sockId0 := range n {
		if arrVis[sockId0] {
			continue
		}
		comp := []int{}
		stack := []int{sockId0}
		arrVis[sockId0] = true
		for len(stack) > 0 {
			lastIdx0 := len(stack) - 1
			node := stack[lastIdx0]
			stack = stack[:lastIdx0]
			comp = append(comp, node)
			for _, adj := range graph[node] {
				if !arrVis[adj] {
					arrVis[adj] = true
					stack = append(stack, adj)
				}
			}
		}
		freq := make(map[int]int)
		for _, node := range comp {
			freq[arrColor[node]]++
		}
		maxFreq := 0
		for _, f := range freq {
			maxFreq = int(math.Max(float64(maxFreq), float64(f)))
		}
		totalChange += len(comp) - maxFreq
	}
	printf("%d", totalChange)
}
func main() {
	defer writer.Flush()
	var n, m, k int
	scan(&n, &m, &k)
	solve(n, m)
}
