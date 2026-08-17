package main

import (
	"bufio"
	"fmt"
	"os"
	"slices"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

func printf(f string, a ...any) { fmt.Fprintf(writer, f, a...) }
func scan(a ...any)             { fmt.Fscan(reader, a...) }
func solve() {
	var n int
	scan(&n)
	arr := make([]int, n)
	for i := range n {
		scan(&arr[i])
	}
	mn := slices.Min(arr)
	cnt := 0
	loc := 1
	for i := range arr {
		if arr[i] == mn {
			cnt++
			if cnt < 2 {
				loc = i + 1
			}
		}
	}
	if cnt > 1 {
		printf("%s\n", "Still Rozdil")
	} else {
		printf("%d\n", loc)
	}
}
func main() {
	defer writer.Flush()
	var t int64
	t = 1
	for range t {
		solve()
	}
}
