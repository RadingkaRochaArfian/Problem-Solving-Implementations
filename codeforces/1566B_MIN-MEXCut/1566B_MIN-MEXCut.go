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
	num := s[0]
	same := true
	count := 0
	if num == '0' {
		count++
	}
	for i := range len(s) - 1 {
		if s[i+1] != num {
			same = false
			if s[i+1] == '0' {
				count++
			}
			num = s[i+1]
		}
	}
	if same {
		if num == '1' {
			printf("0\n")
		} else {
			printf("1\n")
		}
	} else {
		if count > 1 {
			printf("2\n")
		} else {
			printf("1\n")
		}
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
