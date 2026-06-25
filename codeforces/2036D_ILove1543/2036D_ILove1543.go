package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func solve(scanner *bufio.Scanner) {
	var n, m int
	scanner.Scan()
	fmt.Sscanf(scanner.Text(), "%d %d", &n, &m)
	grid := make([][]byte, n)
	for i := range n {
		scanner.Scan()
		grid[i] = []byte(scanner.Text())
	}
	layers := min(n, m) / 2
	ans := 0
	for i := range layers {
		topLine := i
		bottomLine := n - 1 - i
		leftLine := i
		rightLine := m - 1 - i
		line := make([]byte, 0)
		for j := leftLine; j <= rightLine; j++ {
			line = append(line, grid[topLine][j])
		}
		for j := topLine + 1; j <= bottomLine; j++ {
			line = append(line, grid[j][rightLine])
		}
		for j := rightLine - 1; j >= leftLine; j-- {
			line = append(line, grid[bottomLine][j])
		}
		for j := bottomLine - 1; j > topLine; j-- {
			line = append(line, grid[j][leftLine])
		}
		length := len(line)
		target := []byte("1543")
		for j := range length {
			flag := true
			for k := range 4 {
				idx := (j + k) % length
				if line[idx] != target[k] {
					flag = false
					break
				}
			}
			if flag {
				ans++
			}
		}
	}
	fmt.Println(ans)
}
func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	t, _ := strconv.Atoi(scanner.Text())
	for range t {
		solve(scanner)
	}
}
