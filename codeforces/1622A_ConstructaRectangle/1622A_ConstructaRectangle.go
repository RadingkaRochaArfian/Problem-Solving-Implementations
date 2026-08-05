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
	arr := make([]int64, 3)
	for i := range 3 {
		scan(&arr[i])
	}
	ans := "NO"
	for i := range 3 {
		if arr[(i+1)%3]+arr[(i+2)%3] == arr[i] {
			ans = "YES"
		}
	}
	for i := range 3 {
		if arr[i]%2 == 0 && (arr[(i+1)%3] == arr[(i+2)%3]) {
			ans = "YES"
		}
	}
	printf("%s\n", ans)
}
func main() {
	defer writer.Flush()
	var t int64
	scan(&t)
	for range t {
		solve()
	}
}
