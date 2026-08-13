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
	var n, m int
	scan(&n, &m)
	arr := []Coord{}
	for i := 1; i <= n; i++ {
		var s string
		scan(&s)
		for j := 1; j <= m; j++ {
			if s[j-1] == '*' {
				arr = append(arr, Coord{i, j})
			}

		}
	}
	ansX := 1
	ansY := 1
	for i := range 3 {
		if arr[i].x == arr[(i+1)%3].x {
			ansX = arr[(i+2)%3].x
		}
	}
	for i := range 3 {
		if arr[i].y == arr[(i+1)%3].y {
			ansY = arr[(i+2)%3].y
		}
	}
	printf("%d %d\n", ansX, ansY)
}

type Coord struct {
	x, y int
}

func main() {
	defer writer.Flush()
	var t int64
	t = 1
	for range t {
		solve()
	}
}
