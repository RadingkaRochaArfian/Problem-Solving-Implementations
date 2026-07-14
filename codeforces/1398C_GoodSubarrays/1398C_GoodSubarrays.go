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
	var n int
	scan(&n)
	var str string
	scan(&str)
	sumComb := make(map[int]int)
	sumComb[0] = 1
	ans := 0
	sum := 0
	for i := range n {
		sum += int(str[i] - '0')
		checkSum := sum - (i + 1)
		ans += sumComb[checkSum]
		sumComb[checkSum]++
	}
	printf("%d\n", ans)
}
func main() {
	defer writer.Flush()
	var t int
	scan(&t)
	for range t {
		solve()
	}
}
