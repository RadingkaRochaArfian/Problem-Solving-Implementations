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
func primeFactorOf(num int) []int {
	arr := []int{}
	for num%2 == 0 {
		arr = append(arr, 2)
		num /= 2
	}
	for i := 3; i*i <= num; i += 2 {
		for num%i == 0 {
			arr = append(arr, i)
			num /= i
		}
	}
	if num > 1 {
		arr = append(arr, num)
	}
	return arr
}
func sumDigits(num int) int {
	sum := 0
	for num != 0 {
		sum += num % 10
		num /= 10
	}
	return sum
}
func joke(num int) bool {
	arr := primeFactorOf(num)
	if len(arr) == 1 {
		return false
	}
	sumNumDigits := sumDigits(num)
	sumArr := 0
	for i := range arr {
		sumArr += sumDigits(arr[i])
	}
	if sumArr == sumNumDigits {
		return true
	}
	return false
}
func solve() {
	var k int
	scan(&k)
	arr := []int{}
	num := 4
	for len(arr) < k {
		if joke(num) {
			arr = append(arr, num)
		}
		num++
	}
	printf("%d\n", arr[k-1])
}
func main() {
	defer writer.Flush()
	var t int64
	t = 1
	for range t {
		solve()
	}
}
