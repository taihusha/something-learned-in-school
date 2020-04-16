func shiftingLetters(S string, shifts []int) string {
	s := []byte(S)
	shifts = append(shifts, 0)
	for i := len(s) - 1; i >= 0; i-- {
		shifts[i] = (shifts[i] + shifts[i+1]) % 26
		s[i] = 'a' + (s[i]-'a'+byte(shifts[i]))%26
	}
	return string(s)
}