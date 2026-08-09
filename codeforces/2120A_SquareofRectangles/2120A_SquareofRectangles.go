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
	arrW := make([]int, 3)
	arrH := make([]int, 3)
	for i := range 3 {
		scan(&arrW[i], &arrH[i])
	}
	sumW := 0
	for _, x := range arrW {
		sumW += x
	}
	sumH := 0
	for _, x := range arrH {
		sumH += x
	}
	ans := "NO"
	if sumW == arrH[2] && arrH[0] == arrH[1] && arrH[1] == arrH[2] {
		ans = "YES"
	} else if sumH == arrW[2] && arrW[0] == arrW[1] && arrW[1] == arrW[2] {
		ans = "YES"
	} else if (sumW-arrW[0]) == arrW[0] && (arrH[0]+arrH[1]) == arrW[0] && (arrH[0]+arrH[2]) == arrW[0] {
		ans = "YES"
	} else if (sumH-arrH[0]) == arrH[0] && (arrW[0]+arrW[1]) == arrH[0] && (arrW[0]+arrW[2]) == arrH[0] {
		ans = "YES"
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
