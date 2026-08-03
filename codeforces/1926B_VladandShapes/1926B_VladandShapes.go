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
	scan(&n)
	s := make([]string, n)
	for i := range n {
		scan(&s[i])
	}
	firstCnt := 0
	firstRow := -1
	for i := range n {
		for j := range n {
			val := int((s[i][j]) - '0')
			if val == 1 {
				firstRow = i
				for val == 1 && j < n {
					val = int((s[i][j]) - '0')
					if val == 1 {
						firstCnt++
					}
					j++
				}
				break
			}
		}
		if firstRow != -1 {
			break
		}
	}
	secondCnt := 0
	for j := range n {
		val := int(s[firstRow+1][j] - '0')
		if val == 1 {
			secondCnt++
		}
	}
	if firstCnt == secondCnt {
		printf("SQUARE\n")
	} else {
		printf("TRIANGLE\n")
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
