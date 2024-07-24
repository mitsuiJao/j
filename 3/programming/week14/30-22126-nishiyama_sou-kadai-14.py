str1 = input("str1を入力してください：")
print("str1の長さは", len(str1), "です")
str2 = input("str2を入力してください：")
print("str2の長さは", len(str2), "です\n")

if str1 == str2:
    print("str1とstr2は等しいです")
else:
    print("str1とstr2は等しくありません")

print("")

print("str1をstr3としてコピーします")
str3 = str(str1)
print("str3は", str3, "です\n")

str3 += str2
print("str3とstr2を連結したものは", str3, "です\n")

if str3.isalnum():
    print("str3は英数字です")
else:
    print("str3は英数字ではありません")