func lengthOfLastWord(s string) int {
    s = strings.Trim(s, " ")
    if len(s)==0 {
        return 0
    }
    word := strings.Split(s, " ")
    return len(word[len(word)-1])
}