package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func solveFirst(scanner *bufio.Scanner) {
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	line := strings.Fields(scanner.Text())
	arrP := make([]int, n)
	for i := range n {
		arrP[i], _ = strconv.Atoi(line[i])
	}
	pos1, posN := -1, -1
	for i := range n {
		if arrP[i] == 1 {
			pos1 = i
		}
		if arrP[i] == n {
			posN = i
		}
	}
	if pos1 < posN {
		fmt.Println(0)
	} else {
		fmt.Println(1)
	}
	flush()
}
func solveSecond(scanner *bufio.Scanner) {
	scanner.Scan()
	line := strings.Fields(scanner.Text())
	n, _ := strconv.Atoi(line[0])
	x, _ := strconv.Atoi(line[1])
	mostLeft := findMostLeft(n, scanner)
	mostRight := findMostRight(n, scanner)
	var ans int
	if x == 0 {
		ans = mostLeft
	} else {
		ans = mostRight
	}
	fmt.Printf("! %d\n", ans)
	flush()
}
func findMostLeft(n int, scanner *bufio.Scanner) int {
	l, r := 1, n
	for l < r {
		mid := l + (r-l)/2
		if query(1, mid, scanner) == n-1 {
			r = mid
		} else {
			l = mid + 1
		}
	}
	return l
}
func findMostRight(n int, scanner *bufio.Scanner) int {
	l, r := 1, n
	for l < r {
		mid := l + (r-l)/2 + 1
		if query(mid, n, scanner) == n-1 {
			l = mid
		} else {
			r = mid - 1
		}
	}
	return l
}
func query(l, r int, scanner *bufio.Scanner) int {
	fmt.Printf("? %d %d\n", l, r)
	flush()
	scanner.Scan()
	ans, _ := strconv.Atoi(scanner.Text())
	return ans
}

func flush() {
	os.Stdout.Sync()
}
func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Buffer(make([]byte, 1024*1024), 1024*1024)
	scanner.Scan()
	mode := scanner.Text()
	scanner.Scan()
	t, _ := strconv.Atoi(scanner.Text())
	for range t {
		switch mode {
		case "first":
			solveFirst(scanner)
		case "second":
			solveSecond(scanner)
		}
	}
}
