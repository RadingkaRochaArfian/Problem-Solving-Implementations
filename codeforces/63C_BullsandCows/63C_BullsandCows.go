package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

func printf(f string, a ...any) { fmt.Fprintf(writer, f, a...) }
func scan(a ...any)             { fmt.Fscan(reader, a...) }
func solve() {
	var n int
	scan(&n)
	guess, yes, maybe := []int{}, []int{}, []int{}
	for range n {
		var a string
		var b, c int
		scan(&a, &b, &c)
		val, _ := strconv.Atoi(a)
		guess = append(guess, val)
		yes = append(yes, b)
		maybe = append(maybe, c)
	}
	possible := make([]bool, 10000)
	for num := range 10000 {
		if unique(num) {
			possible[num] = true
		}
	}
	for i := range n {
		for num := range 10000 {
			if !possible[num] {
				continue
			}
			b, c := 0, 0
			find(guess[i], num, &b, &c)
			if b != yes[i] || c != maybe[i] {
				possible[num] = false
			}
		}
	}
	count, ans := 0, 0
	for num := range 10000 {
		if possible[num] {
			count++
			ans = num
		}
	}
	switch count {
	case 0:
		printf("Incorrect data\n")
	case 1:
		printf("%04d\n", ans)
	default:
		printf("Need more data\n")
	}
}
func find(guess, num int, b, c *int) {
	a := fmt.Sprintf("%04d", guess)
	a1 := fmt.Sprintf("%04d", num)
	total := 0
	for i := range 4 {
		if a[i] == a1[i] {
			*b++
		}
	}
	for i := range 4 {
		for j := range 4 {
			if a[i] == a1[j] {
				total++
				break
			}
		}
	}
	*c = total - *b
}
func unique(num int) bool {
	digits := make([]bool, 10)
	for range 4 {
		d := num % 10
		num /= 10
		if digits[d] {
			return false
		}
		digits[d] = true
	}
	return true
}
func main() {
	defer writer.Flush()
	var t int64
	t = 1
	for range t {
		solve()
	}
}
