def isPalindrome(n):
    return n == n[::-1]
 
 
n = "katak"
ans = isPalindrome(n)
 
if ans:
    print("Yes")
else:
    print("No")