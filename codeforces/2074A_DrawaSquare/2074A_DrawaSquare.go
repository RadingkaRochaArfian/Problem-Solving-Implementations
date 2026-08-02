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
	arr := make([]int, 4)
	for i := range arr {
		scan(&arr[i])
	}
	same := true
	for i := range len(arr) - 1 {
		if arr[i+1] != arr[i] {
			same = false
			break
		}
	}
	if same {
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
