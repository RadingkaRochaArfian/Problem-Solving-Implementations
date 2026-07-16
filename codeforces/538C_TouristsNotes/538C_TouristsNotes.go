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
func solve(n, m int64) {
	var prevDay, prevHeight int64
	scan(&prevDay, &prevHeight)
	ans := prevHeight + (prevDay - 1)
	can := true
	for i := int64(1); i < m; i++ {
		var currDay, currHeight int64
		scan(&currDay, &currHeight)
		diff := currDay - prevDay
		if math.Abs(float64(currHeight)-float64(prevHeight)) > float64(diff) {
			can = false
		}
		maxBetween := (prevHeight + currHeight + diff) / 2
		ans = int64(math.Max(float64(maxBetween), float64(ans)))
		prevDay = currDay
		prevHeight = currHeight
	}
	diffToEnd := n - prevDay
	ans = int64(math.Max(float64(prevHeight)+float64(diffToEnd), float64(ans)))
	if !can {
		printf("IMPOSSIBLE\n")
	} else {
		printf("%d\n", ans)
	}
}
func main() {
	defer writer.Flush()
	var n, m int64
	scan(&n, &m)
	solve(n, m)
}
