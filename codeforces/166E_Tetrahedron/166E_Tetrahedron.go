package main

import "fmt"

const MOD = 1000000007

func solve(n int64) {
	zD := 1
	zABC := 0
	for range n {
		nzD := int64(zABC*3) % MOD
		nABC := (zABC*2 + zD) % MOD
		zD = int(nzD)
		zABC = int(nABC)
	}
	fmt.Println(zD)
}
func main() {
	var n int64
	fmt.Scan(&n)
	solve(n)
}
