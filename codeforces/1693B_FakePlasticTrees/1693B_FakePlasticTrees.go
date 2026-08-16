package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

func printf(f string, a ...any) { fmt.Fprintf(writer, f, a...) }
func scan(a ...any)             { fmt.Fscan(reader, a...) }
func dfs(ans *int, tree [][]int, arr []Req, node int) int64 {
	sum := int64(0)
	for _, child := range tree[node] {
		sum += dfs(ans, tree, arr, child)
	}
	if sum < int64(arr[node].l) {
		*ans++
		return int64(arr[node].r)
	}
	return min(sum, int64(arr[node].r))
}
func solve() {
	var n int
	scan(&n)
	tree := make([][]int, n+1)
	for i := range tree {
		tree[i] = []int{}
	}
	for i := 2; i <= n; i++ {
		var par int
		scan(&par)
		tree[par] = append(tree[par], i)
	}
	arr := make([]Req, n+1)
	for i := range n {
		var l, r int
		scan(&l, &r)
		node := i + 1
		arr[node].l = l
		arr[node].r = r
	}
	ans := 0
	dfs(&ans, tree, arr, 1)
	printf("%d\n", ans)
}

type Req struct {
	l int
	r int
}

func main() {
	defer writer.Flush()
	var t int64
	scan(&t)
	for range t {
		solve()
	}
}
