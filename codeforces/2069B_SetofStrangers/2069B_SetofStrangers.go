package main

import "fmt"

func solve() {
	var n, m int
	fmt.Scan(&n, &m)
	arr := make([][]int, n)
	for i := range n {
		arr[i] = make([]int, m)
	}
	mapPresent := make(map[int]bool)
	mapHasAdjacent := make(map[int]bool)
	for i := range n {
		for j := range m {
			fmt.Scan(&arr[i][j])
		}
	}
	for i := range n {
		for j := range m {
			num := arr[i][j]
			mapPresent[num] = true
			if i < n-1 && arr[i+1][j] == num {
				mapHasAdjacent[num] = true
			}
			if j < m-1 && arr[i][j+1] == num {
				mapHasAdjacent[num] = true
			}
		}
	}
	maxVal := 0
	total := 0
	for k := range mapPresent {
		hold := 1
		if mapHasAdjacent[k] {
			hold++
		}
		maxVal = max(maxVal, hold)
		total += hold
	}
	fmt.Println(total - maxVal)
}
func main() {
	var t int
	fmt.Scan(&t)
	for range t {
		solve()
	}
}
