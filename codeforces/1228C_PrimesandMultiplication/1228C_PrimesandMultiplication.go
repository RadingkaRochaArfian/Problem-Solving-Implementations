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

const MOD int64 = 1e9 + 7

func findSum(n, p int64) int64 {
	res := int64(0)
	for n/p != 0 {
		res += n / p
		n /= p
	}
	return res
}
func findPow(num, exp int64) int64 {
	res := int64(1)
	for exp != 0 {
		if exp&1 == 1 {
			res = res * num % MOD
		}
		num = num * num % MOD
		exp >>= 1
	}
	return res
}
func solve() {
	var x, n int64
	scan(&x, &n)
	ans := int64(1)
	if x%2 == 0 {
		exp := findSum(n, 2)
		prime := findPow(2, exp)
		ans = prime * ans % MOD
		for x%2 == 0 {
			x /= 2
		}
	}
	for i := int64(3); i*i <= x; i += 2 {
		if x%i == 0 {
			exp := findSum(n, i)
			prime := findPow(i, exp)
			ans = ans * prime % MOD
			for x%i == 0 {
				x /= i
			}
		}
	}
	if x > 1 {
		exp := findSum(n, x)
		prime := findPow(x, exp)
		ans = ans * prime % MOD
	}
	printf("%d\n", ans)
}
func main() {
	defer writer.Flush()
	var t int64
	t = 1
	for range t {
		solve()
	}
}
