package main

import (
	"fmt"
	"sort"
)

func main() {
	var n, d int64
	fmt.Scan(&n, &d)
	solve(n, d)
}

type Vektor struct {
	money int64
	point int64
}

func solve(n, d int64) {
	arrVektor := make([]Vektor, n)
	for i := range n {
		var m, fp int64
		fmt.Scan(&m, &fp)
		arrVektor[i].money = m
		arrVektor[i].point = fp
	}
	sort.Slice(arrVektor, func(i, j int) bool {
		return arrVektor[i].money < arrVektor[j].money
	})
	var ans, total int64
	r := int64(0)
	for l := range n {
		for r < n && arrVektor[r].money-arrVektor[l].money < d {
			total += arrVektor[r].point
			r++
		}
		ans = max(total, ans)
		total -= arrVektor[l].point
	}
	fmt.Println(ans)
}
