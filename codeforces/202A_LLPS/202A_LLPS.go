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
	var s string
	scan(&s)
	mx := byte('a')
	for i := range s {
		mx = byte(max(int(mx), int(s[i])))
	}
	cnt := 0
	for i := range s {
		if s[i] == mx {
			cnt++
		}
	}
	for range cnt {
		printf("%c", mx)
	}
	printf("\n")
}
func main() {
	defer writer.Flush()
	var t int64
	t = 1
	for range t {
		solve()
	}
}
