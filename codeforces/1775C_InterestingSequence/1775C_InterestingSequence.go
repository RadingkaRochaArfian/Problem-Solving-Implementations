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
	var n, x int64
	scan(&n, &x)
	mask := int64(0)
	prohibited := int64(1) << 62
	ans := n
	for i := range 61 {
		if ((n >> i) & 1) == 0 {
			if ((x >> i) & 1) == 1 {
				ans = -1
				break
			}
		} else {
			newNum := n + (int64(1) << i) - (n & mask)
			if ((x >> i) & 1) == 0 {
				ans = max(ans, newNum)
			} else {
				prohibited = min(prohibited, newNum)
			}
		}
		mask += int64(1) << i
	}
	if ans < prohibited {
		printf("%d\n", ans)
	} else {
		printf("-1\n")
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
