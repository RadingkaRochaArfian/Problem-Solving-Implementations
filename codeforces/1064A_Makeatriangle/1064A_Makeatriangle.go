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
	arr := make([]int, 3)
	for i := range 3 {
		scan(&arr[i])
	}
	slices.Sort(arr)
	good := true
	for i := range 3 {
		if arr[i] >= (arr[(i+1)%3] + arr[(i+2)%3]) {
			good = false
			break
		}
	}
	if good {
		printf("0\n")
		return
	}
	ab := arr[0] + arr[1]
	printf("%d\n", arr[2]-ab+1)
}
func main() {
	defer writer.Flush()
	var t int64
	t = 1
	for range t {
		solve()
	}
}
