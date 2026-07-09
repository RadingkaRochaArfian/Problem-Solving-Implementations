package main

import (
	"bufio"
	"os"
	"strconv"
	"strings"
)

func ansQuery(dpHor, dpVer [][]int, writer *bufio.Writer, scanner *bufio.Scanner) {
	scanner.Scan()
	splitLine := strings.Fields(scanner.Text())
	r1, _ := strconv.Atoi(splitLine[0])
	c1, _ := strconv.Atoi(splitLine[1])
	r2, _ := strconv.Atoi(splitLine[2])
	c2, _ := strconv.Atoi(splitLine[3])
	r1--
	c1--
	r2--
	c2--
	ans := 0
	ans += getDp(dpHor, r2, c2-1) - getDp(dpHor, r1-1, c2-1) - getDp(dpHor, r2, c1-1) + getDp(dpHor, r1-1, c1-1)
	ans += getDp(dpVer, r2-1, c2) - getDp(dpVer, r1-1, c2) - getDp(dpVer, r2-1, c1-1) + getDp(dpVer, r1-1, c1-1)
	var sb strings.Builder
	sb.WriteString(strconv.Itoa(ans))
	sb.WriteByte('\n')
	writer.WriteString(sb.String())
}
func solve(r, c int, scanner *bufio.Scanner) {
	grid := make([][]byte, r)
	for i := range r {
		scanner.Scan()
		grid[i] = []byte(scanner.Text())
	}
	dpHor := make([][]int, r)
	dpVer := make([][]int, r)
	for i := range r {
		dpHor[i] = make([]int, c)
		dpVer[i] = make([]int, c)
	}
	findDp(dpHor, dpVer, grid)
	var q int
	scanner.Scan()
	q, _ = strconv.Atoi(scanner.Text())
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()
	for range q {
		ansQuery(dpHor, dpVer, writer, scanner)
	}
}
func findDp(dpHor, dpVer [][]int, grid [][]byte) {
	r := len(dpHor)
	c := len(dpHor[0])
	for i := range r {
		for j := range c {
			dpHor[i][j] = getDp(dpHor, i-1, j) + getDp(dpHor, i, j-1) - getDp(dpHor, i-1, j-1)
			dpVer[i][j] = getDp(dpVer, i-1, j) + getDp(dpVer, i, j-1) - getDp(dpVer, i-1, j-1)
			if grid[i][j] == '.' && j != c-1 && grid[i][j+1] == '.' {
				dpHor[i][j]++
			}
			if grid[i][j] == '.' && i != r-1 && grid[i+1][j] == '.' {
				dpVer[i][j]++
			}
		}
	}
}
func getDp(arr [][]int, r, c int) int {
	if r < 0 || c < 0 {
		return 0
	}
	return arr[r][c]
}
func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	splitLine := strings.Fields(scanner.Text())
	r, _ := strconv.Atoi(splitLine[0])
	c, _ := strconv.Atoi(splitLine[1])
	solve(r, c, scanner)
}
