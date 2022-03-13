package utils

import "github.com/axgle/mahonia"

func CoverGBKToUTF8(src string) string {
	return mahonia.NewDecoder("gbk").ConvertString(src)
}

func CovertUTF8ToGBK(src string) string {
	return mahonia.NewDecoder("utf-8").ConvertString(src)
}
