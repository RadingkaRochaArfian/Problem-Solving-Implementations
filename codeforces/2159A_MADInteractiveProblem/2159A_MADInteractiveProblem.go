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
	s := []int{}
	t := []int{}
	arr := make([]int, 2*n+1)
	s = append(s, 1)
	for i := 2; i <= 2*n; i++ {
		printf("? %d ", len(s)+1)
		for j := range s {
			printf("%d ", s[j])
		}
		printf("%d\n", i)
		writer.Flush()
		var x int
		scan(&x)
		if x != 0 {
			arr[i] = x
			t = append(t, i)
		} else {
			s = append(s, i)
		}
	}
	for len(s) != 0 {
		top := len(s) - 1
		v := s[top]
		s = s[:top]
		printf("? %d ", len(t)+1)
		for i := range t {
			printf("%d ", t[i])
		}
		printf("%d\n", v)
		writer.Flush()
		scan(&arr[v])
	}
	printf("! ")
	for i := 1; i < 2*n+1; i++ {
		printf("%d ", arr[i])
	}
	printf("\n")
	writer.Flush()
}
func main() {
	defer writer.Flush()
	var t int64
	scan(&t)
	for range t {
		solve()
	}
}
