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
	var s []byte
	scan(&s)
	bad := 0
	ans := "YES"
	for i := range len(s) - 1 {
		if s[i] == s[i+1] {
			bad++
		}
	}
	if bad > 2 {
		ans = "NO"
	}
	printf("%s\n", ans)
}
func main() {
	defer writer.Flush()
	var t int64
	scan(&t)
	for range t {
		solve()
	}
}
