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
	arr := make([]string, 3)
	for i := range 3 {
		scan(&arr[i])
	}
	var line string
	for i := range 3 {
		for j := range 3 {
			if arr[i][j] == '?' {
				line = arr[i]
				break
			}
		}
		if line != "" {
			break
		}
	}
	mask := 0
	for _, v := range line {
		if v != '?' {
			mask ^= int(v)
		}
	}
	totalXor := int('A') ^ int('B') ^ int('C')
	printf("%c\n", totalXor^mask)
}
func main() {
	defer writer.Flush()
	var t int
	scan(&t)
	for range t {
		solve()
	}
}
