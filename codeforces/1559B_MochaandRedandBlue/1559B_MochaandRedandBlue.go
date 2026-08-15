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
	var n int
	var s []byte
	scan(&n, &s)
	cnt := 0
	for _, c := range s {
		if c != '?' {
			cnt++
		}
	}
	if cnt == 0 {
		s[0] = 'R'
	}
	for i := 1; i < n; i++ {
		if s[i] == '?' && s[i-1] != '?' {
			s[i] = s[i-1] ^ ('B' ^ 'R')
		}
	}
	for i := n - 2; i >= 0; i-- {
		if s[i] == '?' {
			s[i] = s[i+1] ^ ('B' ^ 'R')
		}
	}
	for _, c := range s {
		printf("%c", c)
	}
	printf("\n")
}
func main() {
	defer writer.Flush()
	var t int64
	scan(&t)
	for range t {
		solve()
	}
}
