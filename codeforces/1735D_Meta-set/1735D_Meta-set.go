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
	card := make([][20]int, n)
	for i := range n {
		for j := range k {
			scan(&card[i][j])
		}
	}
	cnt := make(map[[20]int]int64)
	for i := range n {
		for j := i + 1; j < n; j++ {
			centerCard := findCard(card[i], card[j], k)
			cnt[centerCard]++
		}
	}
	ans := int64(0)
	for i := range card {
		ans += cnt[card[i]] * (cnt[card[i]] - 1) / 2
	}
	printf("%d\n", ans)
}
func findCard(a, b [20]int, k int) [20]int {
	var res [20]int
	for i := range k {
		res[i] = (6 - a[i] - b[i]) % 3
	}
	return res
}
func main() {
	defer writer.Flush()
	var t int64
	t = 1
	for range t {
		solve()
	}
}
