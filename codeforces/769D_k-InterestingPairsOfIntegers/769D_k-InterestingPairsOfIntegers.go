package main

import (
	"bufio"
	"fmt"
	"math/bits"
	"os"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

func printf(f string, a ...any) { fmt.Fprintf(writer, f, a...) }
func scan(a ...any)             { fmt.Fscan(reader, a...) }
func solve() {
	var n, k int
	scan(&n, &k)
	arr := make([]int, n)
	cnt := make([]int, 10004)
	for i := range n {
		scan(&arr[i])
		cnt[arr[i]]++
	}
	ans := int64(0)
	if k == 0 {
		for i := range 10001 {
			if cnt[i] >= 2 {
				ans += int64(cnt[i]) * int64(cnt[i]-1) / 2
			}
		}
	} else {
		for i := range 10001 {
			if cnt[i] == 0 {
				continue
			}
			for j := i + 1; j <= 10000; j++ {
				if cnt[j] == 0 {
					continue
				}
				if bits.OnesCount(uint(i^j)) == k {
					ans += int64(cnt[i]) * int64(cnt[j])
				}
			}
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
