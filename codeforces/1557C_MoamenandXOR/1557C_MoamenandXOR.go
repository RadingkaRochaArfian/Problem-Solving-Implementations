package main

import (
	"bufio"
	"fmt"
	"os"
)

const MOD = int64(1e9 + 7)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

func printf(f string, a ...any) { fmt.Fprintf(writer, f, a...) }
func scan(a ...any)             { fmt.Fscan(reader, a...) }
func dp(mostLeft, n int, equal bool, evenCombs, mxComb int64, state *DpState) int64 {
	if mostLeft == -1 {
		return 1
	}
	idx := 0
	if equal {
		idx = 1
	}
	if state.vis[mostLeft][idx] {
		return state.memo[mostLeft][idx]
	}
	var res int64
	if equal {
		if n%2 == 1 {
			bit1OnBitPosChoice := (evenCombs + 1) % MOD
			res = (bit1OnBitPosChoice * dp(mostLeft-1, n, true, evenCombs, mxComb, state)) % MOD
		} else {
			bit1OnBitPosChoice := (evenCombs - 1 + MOD) % MOD
			res = (bit1OnBitPosChoice * dp(mostLeft-1, n, true, evenCombs, mxComb, state)) % MOD
			more := dp(mostLeft-1, n, false, evenCombs, mxComb, state)
			res = (res + more) % MOD
		}
	} else {
		res = mxComb * dp(mostLeft-1, n, false, evenCombs, mxComb, state) % MOD
	}
	state.memo[mostLeft][idx] = res
	state.vis[mostLeft][idx] = true
	return res
}
func solve() {
	var n, k int
	scan(&n, &k)
	evenCombs := int64(0)
	for i := 0; i <= n; i += 2 {
		evenCombs = (evenCombs + nCr(n, i)) % MOD
	}
	mxComb := twoPow(n)
	state := initDpState(k)
	ans := dp(k-1, n, true, evenCombs, mxComb, state)
	printf("%d\n", ans)
}

type DpState struct {
	memo [][]int64
	vis  [][]bool
}

func initDpState(k int) *DpState {
	memo := make([][]int64, k)
	vis := make([][]bool, k)
	for i := range k {
		memo[i] = make([]int64, 2)
		vis[i] = make([]bool, 2)
	}
	return &DpState{memo, vis}
}
func twoPow(k int) int64 {
	res := int64(1)
	for range k {
		res = (res * 2) % MOD
	}
	return res
}

var fact, invFact, inv []int64

func preCompute() {
	mxN := int(2e5 + 1)
	fact = make([]int64, mxN)
	invFact = make([]int64, mxN)
	inv = make([]int64, mxN)
	fact[0], inv[1], fact[1], invFact[0], invFact[1] = 1, 1, 1, 1, 1
	for i := 2; i < mxN; i++ {
		fact[i] = (fact[i-1] * int64(i)) % MOD
		inv[i] = MOD - (inv[MOD%int64(i)] * (MOD / int64(i)) % MOD)
		invFact[i] = (inv[i] * invFact[i-1]) % MOD
	}
}
func nCr(n, r int) int64 {
	res := fact[n] * invFact[r] % MOD
	res = res * invFact[n-r] % MOD
	return res
}
func main() {
	defer writer.Flush()
	preCompute()
	var t int64
	scan(&t)
	for range t {
		solve()
	}
}
