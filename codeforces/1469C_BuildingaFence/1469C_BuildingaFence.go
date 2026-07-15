package main

import (
	"bufio"
	"fmt"
	"os"
)

var writer *bufio.Writer = bufio.NewWriter(os.Stdout)
var reader *bufio.Reader = bufio.NewReader(os.Stdin)

func printf(f string, a ...any) { fmt.Fprintf(writer, f, a...) }
func scan(a ...any)             { fmt.Fscan(reader, a...) }
func solve() {
	var n, k int64
	scan(&n, &k)
	arrGL := make([]int64, n)
	for i := range n {
		scan(&arrGL[i])
	}
	mn := arrGL[0]
	mx := arrGL[0]
	for i := int64(1); i < n; i++ {
		mn = max(mn-(k-1), arrGL[i])
		mx = min(mx+k-1, arrGL[i]+k-1)
		if mn > mx {
			printf("NO\n")
			return
		}
	}
	if arrGL[n-1] < mn || arrGL[n-1] > mx {
		printf("NO\n")
		return
	}
	printf("YES\n")
}
func main() {
	defer writer.Flush()
	var t int
	scan(&t)
	for range t {
		solve()
	}
}
