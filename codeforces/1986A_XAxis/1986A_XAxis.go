package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"slices"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

func printf(f string, a ...any) { fmt.Fprintf(writer, f, a...) }
func scan(a ...any)             { fmt.Fscan(reader, a...) }
func solve() {
	arr := []int{}
	for range 3 {
		var x int
		scan(&x)
		arr = append(arr, x)
	}
	slices.Sort(arr)
	a := int(math.Abs(float64(arr[1] - arr[0])))
	b := int(math.Abs(float64(arr[1] - arr[2])))
	printf("%d\n", a+b)
}
func main() {
	defer writer.Flush()
	var t int64
	scan(&t)
	for range t {
		solve()
	}
}
