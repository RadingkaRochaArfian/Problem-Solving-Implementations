package main

import (
	"bufio"
	"fmt"
	"math"
	"math/bits"
	"os"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

func printf(f string, a ...any) { fmt.Fprintf(writer, f, a...) }
func scan(a ...any)             { fmt.Fscan(reader, a...) }
func solve() {
	var n int
	scan(&n)
	arr := make([]int, n)
	mnPow := math.MaxInt
	even := 0
	for i := range n {
		scan(&arr[i])
		mnPow = min(mnPow, bits.TrailingZeros(uint(arr[i])))
		if arr[i]%2 == 0 {
			even++
		}
	}
	ans := even + max(0, mnPow-1)
	printf("%d\n", ans)
}
func main() {
	defer writer.Flush()
	var t int64
	scan(&t)
	for range t {
		solve()
	}
}
