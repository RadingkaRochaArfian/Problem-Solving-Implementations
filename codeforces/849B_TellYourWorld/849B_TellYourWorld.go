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
func check(n, b int64, y []int64, slope float64) bool {
	line1 := make([]bool, n+1)
	cnt := int64(0)
	for i := range n {
		x := i + 1
		left := float64(y[x] - b)
		right := slope * float64(x-1)
		if left == right {
			line1[x] = true
			cnt++
		}
	}
	if cnt == n {
		return false
	}
	if cnt == n-1 {
		return true
	}
	firstPos := int64(0)
	for i := range n + 1 {
		x := i + 1
		if !line1[x] {
			firstPos = x
			break
		}
	}
	for i := firstPos + 1; i <= n; i++ {
		if !line1[i] {
			var slope2 float64 = float64(y[i]-y[firstPos]) / float64(i-firstPos)
			diff := math.Abs(slope2 - slope)
			epsilon := 1e-7
			if diff > epsilon {
				return false
			}
		}
	}
	return true
}
func solve(n int64) {
	arr := make([]int64, n+1)
	for i := range n {
		scan(&arr[i+1])
	}
	a := arr[1]
	b := arr[2]
	c := arr[3]
	slope1 := float64(b-a) / (2 - 1)
	b1 := a
	slope2 := float64(c-a) / (3 - 1)
	slope3 := float64(c-b) / (3 - 2)
	b3 := 2*b - c
	if check(n, b1, arr, slope1) {
		printf("Yes\n")
		return
	}
	if check(n, b1, arr, slope2) {
		printf("Yes\n")
		return
	}
	if check(n, b3, arr, slope3) {
		printf("Yes\n")
		return
	}
	printf("No\n")
}
func main() {
	defer writer.Flush()
	var n int64
	scan(&n)
	solve(n)
}
