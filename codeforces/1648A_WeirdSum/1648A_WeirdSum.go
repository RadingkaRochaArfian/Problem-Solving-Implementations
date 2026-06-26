package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func solve(n, m int, reader *bufio.Reader) {
	mapColor := make(map[int][][2]int)
	for i := range n {
		line, _ := reader.ReadString('\n')
		nums := strings.Fields(line)
		for j := range m {
			color, _ := strconv.Atoi(nums[j])
			mapColor[color] = append(mapColor[color], [2]int{i, j})
		}
	}
	var total int64
	for _, val := range mapColor {
		total += calculateSumByColor(val)
	}
	fmt.Println(total)
}
func calculateSumByColor(val [][2]int) int64 {
	k := len(val)
	if k < 2 {
		return 0
	}
	arrRow := make([]int, k)
	arrCol := make([]int, k)
	for i, cell := range val {
		arrRow[i] = cell[0]
		arrCol[i] = cell[1]
	}
	sort.Ints(arrRow)
	sort.Ints(arrCol)
	sumRow := calculateSum(arrRow)
	sumCol := calculateSum(arrCol)
	return sumCol + sumRow
}
func calculateSum(arr []int) int64 {
	k := len(arr)
	var total int64 = 0
	for i := range k {
		c := int64(2*i + 1 - k)
		total += c * int64(arr[i])
	}
	return total
}
func main() {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	parts := strings.Fields(line)
	n, _ := strconv.Atoi(parts[0])
	m, _ := strconv.Atoi(parts[1])
	solve(n, m, reader)
}
