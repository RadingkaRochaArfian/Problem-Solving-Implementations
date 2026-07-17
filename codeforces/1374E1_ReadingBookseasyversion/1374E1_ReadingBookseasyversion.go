package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"slices"
)

var writer *bufio.Writer = bufio.NewWriter(os.Stdout)
var reader *bufio.Reader = bufio.NewReader(os.Stdin)

func printf(f string, a ...any) { fmt.Fprintf(writer, f, a...) }
func scan(a ...any)             { fmt.Fscan(reader, a...) }
func solve(n, k int64) {
	arrC := []int64{}
	arrB := []int64{}
	arrA := []int64{}
	for range n {
		var x, a, b int64
		scan(&x, &a, &b)
		if a == 1 && b == 1 {
			arrC = append(arrC, x)
		} else if b == 1 {
			arrB = append(arrB, x)
		} else if a == 1 {
			arrA = append(arrA, x)
		}
	}
	nA := int64(len(arrA))
	nB := int64(len(arrB))
	nC := int64(len(arrC))
	slices.Sort(arrA)
	slices.Sort(arrB)
	slices.Sort(arrC)
	prefix11 := make([]int64, nC+1)
	prefix10 := make([]int64, nA+1)
	prefix01 := make([]int64, nB+1)
	for i := range arrC {
		prefix11[i+1] = prefix11[i] + arrC[i]
	}
	for i := range arrB {
		prefix01[i+1] = prefix01[i] + arrB[i]
	}
	for i := range arrA {
		prefix10[i+1] = prefix10[i] + arrA[i]
	}
	ans := int64(math.MaxInt64)
	for i := range int64(math.Min(float64(k), float64(nC))) + 1 {
		need := k - i
		if need < 0 || need > nB || need > nA {
			continue
		}
		total := prefix11[i] + prefix01[need] + prefix10[need]
		ans = int64(math.Min(float64(ans), float64(total)))
	}
	if ans == math.MaxInt64 {
		printf("-1\n")
	} else {
		printf("%d\n", ans)
	}
}
func main() {
	defer writer.Flush()
	var n, k int64
	scan(&n, &k)
	solve(n, k)
}
