package main

import (
	"bufio"
	"fmt"
	"math"
	"math/bits"
	"os"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

func printf(f string, a ...any) { fmt.Fprintf(writer, f, a...) }
func scan(a ...any)             { fmt.Fscan(reader, a...) }
func getMask(s string) int {
	mask := 0
	switch s[0] {
	case 'R':
		mask |= (1 << 0)
	case 'G':
		mask |= (1 << 1)
	case 'B':
		mask |= (1 << 2)
	case 'Y':
		mask |= (1 << 3)
	case 'W':
		mask |= (1 << 4)
	}
	mask |= 1 << (int(s[1]-'1') + 5)
	return mask
}
func solve() {
	var n int
	scan(&n)
	arr := make(map[int]struct{})
	for range n {
		var s string
		scan(&s)
		mask := getMask(s)
		arr[mask] = struct{}{}
	}
	ans := math.MaxInt32
	for i := range 1 << 10 {
		vis := make(map[int]int)
		diff := true
		for key := range arr {
			info := key & i
			if vis[info] > 0 {
				diff = false
				break
			}
			vis[info]++
		}
		if diff {
			ans = min(ans, bits.OnesCount(uint(i)))
		}
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
