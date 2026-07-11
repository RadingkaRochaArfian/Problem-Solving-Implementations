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
func scanf(f string, a ...any)  { fmt.Fscanf(reader, f, a...) }
func solve(r, c int) {
	totalDiag := r + c - 1
	diagA := make([][]int64, totalDiag)
	diagB := make([][]int64, totalDiag)
	for i := range r {
		for j := range c {
			var x int64
			scanf("%d", &x)
			idx := i + j
			diagA[idx] = append(diagA[idx], x)
		}
		scanf("\n")
	}
	for i := range r {
		for j := range c {
			var x int64
			scanf("%d", &x)
			idx := i + j
			diagB[idx] = append(diagB[idx], x)
		}
		scanf("\n")
	}
	sortSlice(diagA)
	sortSlice(diagB)
	if similar(diagA, diagB) {
		printf("YES\n")
	} else {
		printf("NO\n")
	}
}
func similar(diagA, diagB [][]int64) bool {
	for i := range diagA {
		a := diagA[i]
		b := diagB[i]
		if len(a) != len(b) {
			return false
		}
		for j := range a {
			if a[j] != b[j] {
				return false
			}
		}
	}
	return true
}
func sortSlice(slice [][]int64) {
	for i := range slice {
		slices.Sort(slice[i])
	}
}
func main() {
	defer writer.Flush()
	var r, c int
	scanf("%d %d\n", &r, &c)
	solve(r, c)
}
