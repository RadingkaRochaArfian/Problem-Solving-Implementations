package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

func printf(f string, a ...any) { fmt.Fprintf(writer, f, a...) }
func scanf(f string, a ...any)  { fmt.Fscanf(reader, f, a...) }

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}
func main() {
	defer writer.Flush()
	var a, b int
	scanf("%d %d", &a, &b)
	gcdVal := gcd(a, b)
	a /= gcdVal
	b /= gcdVal
	if math.Abs(float64(a)-float64(b)) == 1 {
		printf("Equal\n")
	} else if a < b {
		printf("Dasha\n")
	} else {
		printf("Masha\n")
	}
}
