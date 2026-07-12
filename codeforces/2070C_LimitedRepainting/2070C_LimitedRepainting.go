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
func solve() {
	var n, k int
	scan(&n, &k)
	targetPenalty := make([]int, n)
	var s string
	scan(&s)
	targetColor := []rune(s)
	for i := range n {
		scan(&targetPenalty[i])
	}
	ans := findResult(targetColor, targetPenalty, n, k)
	printf("%d\n", ans)
}
func findResult(color []rune, penalty []int, n, k int) int64 {
	var low int64
	var high int64 = 1e9
	var res int64
	for low <= high {
		mid := low + (high-low)/2
		if check(color, penalty, n, k, mid) {
			res = mid
			high = mid - 1
		} else {
			low = mid + 1
		}
	}
	return res
}
func check(color []rune, penalty []int, n, k int, ignore int64) bool {
	last := 'R'
	var count int64
	for i := range n {
		if int64(penalty[i]) > ignore {
			if color[i] == 'B' && last == 'R' {
				count++
			}
			last = color[i]
		}
	}
	if count > int64(k) {
		return false
	} else {
		return true
	}
}
func main() {
	defer writer.Flush()
	var t int
	scan(&t)
	for range t {
		solve()
	}
}
