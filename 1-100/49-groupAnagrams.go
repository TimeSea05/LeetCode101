package main

import (
	"fmt"
	"sort"
	"strings"
)

type Word struct {
	origin   string
	encoding string
}

type Words []Word

func (words Words) Len() int {
	return len(words)
}

func (words Words) Less(i, j int) bool {
	return words[i].encoding < words[j].encoding
}

func (words Words) Swap(i, j int) {
	words[i], words[j] = words[j], words[i]
}

func encode(str string) string {
	cnt := make([]int, 26)
	convStr := []byte(str)
	for _, b := range convStr {
		cnt[b-'a']++
	}

	var sb strings.Builder
	for _, num := range cnt {
		sb.WriteString(fmt.Sprintf("%d,", num))
	}

	return sb.String()
}

func groupAnagrams(strs []string) [][]string {
	groupedAnagrams := make([][]string, 0)

	words := make([]Word, len(strs))
	for i := 0; i < len(words); i++ {
		words[i].origin = strs[i]
		words[i].encoding = encode(strs[i])
	}
	sort.Sort(Words(words))

	var encodedStr = words[0].encoding
	var lastGrouped = -1
	for i := 1; i < len(words); i++ {
		if words[i].encoding != encodedStr {
			anagrams := make([]string, 0)
			for j := lastGrouped + 1; j < i; j++ {
				anagrams = append(anagrams, words[j].origin)
			}
			groupedAnagrams = append(groupedAnagrams, anagrams)
			encodedStr = words[i].encoding
			lastGrouped = i - 1
		}
	}

	anagrams := make([]string, 0)
	for j := lastGrouped + 1; j < len(words); j++ {
		anagrams = append(anagrams, words[j].origin)
	}
	groupedAnagrams = append(groupedAnagrams, anagrams)

	return groupedAnagrams
}

func main() {
	fmt.Println(groupAnagrams([]string{"a"}))
}
