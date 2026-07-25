package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

func printf(f string, a ...any) { fmt.Fprintf(writer, f, a...) }
func scan(a ...any)             { fmt.Fscan(reader, a...) }
func dfs(n int64, cost, next []int64) int64 {
	sum := int64(0)
	state := make([]int, n+1)
	path := []int64{}
	var findCycle func(int64)
	findCycle = func(room int64) {
		state[room] = 1
		path = append(path, room)
		to := next[room]
		if state[to] == 0 {
			findCycle(to)
		} else if state[to] == 1 {
			minCost := int64(math.MaxInt64)
			for i := len(path) - 1; i >= 0; i-- {
				if path[i] == to {
					for j := i; j < len(path); j++ {
						minCost = min(cost[path[j]], minCost)
					}
					break
				}
			}
			sum += minCost
		}
		path = path[:len(path)-1]
		state[room] = 2
	}
	for i := range n {
		room := i + 1
		if state[room] == 0 {
			findCycle(room)
		}
	}
	return sum
}
func solve() {
	var n int64
	scan(&n)
	cost := make([]int64, n+1)
	for i := range n {
		room := i + 1
		scan(&cost[room])
	}
	next := make([]int64, n+1)
	for i := range n {
		room := i + 1
		scan(&next[room])
	}
	sum := dfs(n, cost, next)
	printf("%d\n", sum)
}
func main() {
	defer writer.Flush()
	var t int64
	t = 1
	for range t {
		solve()
	}
}
