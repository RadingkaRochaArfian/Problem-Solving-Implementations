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
	var n, l int
	scan(&n, &l)
	arr := make([]int, n)
	for i := range n {
		scan(&arr[i])
	}
	ans := 0
	for i := range l {
		cnt1 := 0
		for j := range n {
			if (arr[j]>>i)&1 == 1 {
				cnt1++
			}
		}
		if cnt1 >= (n - cnt1) {
			ans |= (1 << i)
		}
	}
	printf("%d\n", ans)
}
func main() {
	defer writer.Flush()
	var t int64
	scan(&t)
	for range t {
		solve()
	}
}
