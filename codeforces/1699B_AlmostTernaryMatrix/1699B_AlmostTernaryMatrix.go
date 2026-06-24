package main

import "fmt"

func solve() {
	var n, m int
	fmt.Scan(&n, &m)
	for i := range n {
		for j := range m {
			blockI := i / 2
			blockJ := j / 2
			checkI := i % 2
			checkJ := j % 2
			if (blockI+blockJ)%2 == 1 {
				if checkI == checkJ {
					fmt.Print(0)
				} else {
					fmt.Print(1)
				}
			} else {
				if checkI == checkJ {
					fmt.Print(1)
				} else {
					fmt.Print(0)
				}
			}
			if j < m-1 {
				fmt.Print(" ")
			}
		}
		fmt.Println()
	}
}
func main() {
	var t int
	fmt.Scan(&t)
	for range t {
		solve()
	}
}
