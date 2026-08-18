package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

func printf(f string, a ...any) { fmt.Fprintf(writer, f, a...) }
func scan(a ...any)             { fmt.Fscan(reader, a...) }
func solve() {
	var n int
	scan(&n)
	var s1 string
	scan(&s1)
	var s2 strings.Builder
	for _, c := range s1 {
		check, _ := strconv.Atoi(string(c))
		if check%2 != 0 {
			s2.WriteRune(c)
		}
	}
	if s2.Len()%2 == 1 {
		s := s2.String()
		r := []rune(s)
		r = r[:len(r)-1]
		s2.Reset()
		s2.WriteString(string(r))
	}
	if s2.Len() == 0 || n == 1 {
		printf("-1\n")
	} else {
		printf("%s\n", s2.String())
	}
}
func main() {
	defer writer.Flush()
	var t int64
	scan(&t)
	for range t {
		solve()
	}
}
