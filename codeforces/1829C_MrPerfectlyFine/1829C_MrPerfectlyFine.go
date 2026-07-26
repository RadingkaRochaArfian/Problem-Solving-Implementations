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
func scan(a ...any)             { fmt.Fscan(reader, a...) }
func solve() {
	var n int
	scan(&n)
	mp := make(map[int]int)
	for i := range 4 {
		mp[i] = math.MaxInt
	}
	for range n {
		var m int
		var s string
		scan(&m, &s)
		mask := 0
		if s[0] == '1' {
			mask |= 2
		}
		if s[1] == '1' {
			mask |= 1
		}
		mp[mask] = min(mp[mask], m)
	}
	ans := math.MaxInt
	if mp[1] != math.MaxInt && mp[2] != math.MaxInt {
		ans = min(ans, mp[1]+mp[2])
	}
	if mp[3] != math.MaxInt {
		ans = min(ans, mp[3])
	}
	if ans == math.MaxInt {
		ans = -1
	}
	printf("%d\n", ans)
}
func main() {
	defer writer.Flush()
	var t int64
	scan(&t)
	for range t {
		solve()
	}
}
