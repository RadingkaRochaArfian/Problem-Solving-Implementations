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
	arr := make([]int64, 2)
	for i := range 2 {
		scan(&arr[i])
	}
	good := false
	for i := range 2 {
		if arr[i]%2 == 0 && (arr[i]/2 != arr[(i+1)%2]) {
			good = true
		}
	}
	if good {
		printf("Yes\n")
	} else {
		printf("No\n")
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
