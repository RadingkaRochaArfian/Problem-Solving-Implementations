package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

func printf(f string, a ...any) { fmt.Fprintf(writer, f, a...) }
func scan(a ...any)             { fmt.Fscan(reader, a...) }

type TwoWord struct {
	s1 string
	s2 string
}

func solve() {
	var n int
	scan(&n)
	mpLyricByVowel := make(map[int]map[byte][]string)
	for range n {
		var s string
		scan(&s)
		totalVowel := findTotalVowel(s)
		lastVowel := findLastVowel(s)
		if mpLyricByVowel[totalVowel] == nil {
			mpLyricByVowel[totalVowel] = make(map[byte][]string)
		}
		mpLyricByVowel[totalVowel][lastVowel] = append(mpLyricByVowel[totalVowel][lastVowel], s)
	}
	fullDuo := []TwoWord{}
	halfDuo := []TwoWord{}
	for _, mpTotalVowel := range mpLyricByVowel {
		for i, arrLastVowel := range mpTotalVowel {
			tempArr := arrLastVowel
			for len(tempArr) >= 2 {
				top := len(tempArr) - 1
				s1 := tempArr[top]
				s2 := arrLastVowel[top-1]
				tempArr = tempArr[:(top - 1)]
				fullDuo = append(fullDuo, TwoWord{s1, s2})
			}
			mpTotalVowel[i] = tempArr
		}
		arrRemainLastVowel := []string{}
		for _, arrLastVowel := range mpTotalVowel {
			for _, lyric := range arrLastVowel {
				arrRemainLastVowel = append(arrRemainLastVowel, lyric)
			}
		}
		for len(arrRemainLastVowel) >= 2 {
			top := len(arrRemainLastVowel) - 1
			s1 := arrRemainLastVowel[top]
			s2 := arrRemainLastVowel[top-1]
			arrRemainLastVowel = arrRemainLastVowel[:top-1]
			halfDuo = append(halfDuo, TwoWord{s1, s2})
		}
	}
	arrAns := []TwoWord{}
	for len(fullDuo) != 0 && len(halfDuo) != 0 {
		top := len(fullDuo) - 1
		FullWord := fullDuo[top]
		fullDuo = fullDuo[:top]
		top = len(halfDuo) - 1
		halfWord := halfDuo[top]
		halfDuo = halfDuo[:top]
		arrAns = append(arrAns, TwoWord{halfWord.s1, FullWord.s1})
		arrAns = append(arrAns, TwoWord{halfWord.s2, FullWord.s2})
	}
	for len(fullDuo) >= 2 {
		top := len(fullDuo) - 1
		arrAns = append(arrAns, TwoWord{fullDuo[top].s1, fullDuo[top-1].s1})
		arrAns = append(arrAns, TwoWord{fullDuo[top].s2, fullDuo[top-1].s2})
		fullDuo = fullDuo[:top-1]
	}
	printf("%d\n", len(arrAns)/2)
	for _, line := range arrAns {
		printf("%s %s\n", line.s1, line.s2)
	}
}
func findLastVowel(s string) byte {
	n := len(s)
	idx := 0
	for i := n - 1; i >= 0; i-- {
		x := rune(s[i])
		if isVowel(x) {
			idx = i
			break
		}
	}
	return s[idx]
}
func findTotalVowel(s string) int {
	sum := 0
	for _, x := range s {
		if isVowel(x) {
			sum++
		}
	}
	return sum
}
func isVowel(c rune) bool {
	return c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o'
}
func main() {
	defer writer.Flush()
	var t int64
	t = 1
	for range t {
		solve()
	}
}
